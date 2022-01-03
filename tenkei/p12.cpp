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

int H, W;


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
};

int getNumber(int r, int c){
    return (r-1)*W + c;
}

int main(){
    cin >> H >> W;
    int Q;
    cin >> Q;

    int num = getNumber(H, W);
    UnionFind tree = UnionFind(num+1);
    vector<vector<int>> Square(H+1, vector<int>(W+1, 0));
    
    vector<string> ans;
    REP(i, Q){
        int flag;
        cin >> flag;
        if(flag == 1){
            int r, c;
            cin >> r >> c;
            Square[r][c] = 1;

            for(pair<int, int>dxy : {pair<int, int>(1, 0), pair<int, int>(0, -1), pair<int, int>(-1, 0), pair<int, int>(0, 1)}){
                
                int di = dxy.first;
                int dj = dxy.second;
                if(r + di <= H && r + di >= 1 && c + dj <= W && c + dj >= 1 ){
                    if(Square[r+di][c+dj] == 1){
                        tree.unite(getNumber(r, c), getNumber(r+di, c+dj));
                    }
                }
            }

        }else{
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if(Square[ra][ca] != 1 || Square[rb][cb] != 1){
                ans.push_back("No");
                // que.push("No");
                continue;
            }

            if(tree.same(getNumber(ra,ca), getNumber(rb,cb))){
                ans.push_back("Yes");
            }else{
                ans.push_back("No");
            }
        }
    }

    for(string s : ans){
        cout << s << endl;
    }

    return 0;
}