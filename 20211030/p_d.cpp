#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void split(int x, int y){
        par[y] = y;
    }
};


int search(vector<pair<int, int>> &train, int target){
    if(train[target].second == target){
        return target;
    }
    return search(train, train[target].second);
}


int main(){
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> train(N+1);
    REP(i, N+1){
        train[i] = pair<int, int>(i, i);
    }

    queue<vector<int>> ansQ;


    REP(i, Q){
        int c;
        cin >> c;

        if(c == 1){
            int x, y;
            cin >> x >> y;
            train[x].first = y;
            train[y].second = x;
        }

        if(c == 2){
            int x, y;
            cin >> x >> y;
            train[x].first = x;
            train[y].second = y;
        }

        if(c == 3){
            int x;
            cin >> x;

            int parent = search(train, x);
            vector<int> ans;
            while (true)
            {
                ans.push_back(parent);
                if(train[parent].first == parent){
                    break;
                }
                parent = train[parent].first;
            }

            ansQ.push(ans);
            
        }
    }

    while(!ansQ.empty()){
        vector<int> ans = ansQ.front(); ansQ.pop();

        cout << ans.size() << " ";
        REP(i, ans.size()){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}