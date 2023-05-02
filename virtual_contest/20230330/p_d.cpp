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
#define REPREV(i,n) for(int i=(n-1);i>=(0);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

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
 
 
bool isBridge(vector<pair<int, int>>& edges, int idx, int N, int M){
    UnionFind groups = UnionFind(N);
 
    REP(i, M){
        if(i==idx)continue;
        auto edge = edges[i];
        int node_i = edge.first;
        int node_j = edge.second;
        groups.unite(node_i, node_j);
    }
 
    FOR(i, 1, N){
        if(groups.same(0, i) == false){
            return true;
        }
    }
    return false;
}
 
int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges;
    REP(i, M){
        int a, b;
        cin >> a >> b;
        edges.push_back({a-1, b-1});
    }
 
    int ans = 0;
    REP(idx, M){
        if(isBridge(edges, idx, N, M)){
            ans += 1;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}