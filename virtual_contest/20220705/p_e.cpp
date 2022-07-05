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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

// ２部グラフ問題と同じ考え方をする　
// https://qiita.com/drken/items/a803d4fc4a727e02f7ba
bool dfs(Graph& G, vector<LL>& dist, int inode, vector<bool>& visited){
    for(auto edge: G[inode]){
        if(visited[edge.to] == false){
            // 未探索
            dist[edge.to] = dist[inode] + edge.w;
            visited[edge.to] = true;
            // return ではなく子の結果を使って分岐
            if(dfs(G, dist, edge.to, visited) == false){
                return false;
            }
        }else{
            if(dist[edge.to] != dist[inode] + edge.w){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N+1);
    REP(i, M) {
        int l, r;
        LL d;
        cin >> l >> r >> d;
        G[l].push_back(Edge(r, d));
        G[r].push_back(Edge(l, -d));
    }

    vector<LL> dist(N+1, 0);
    vector<bool> visited(N+1, false);
    dist[0] = 0;
    visited[0] = true;
    REP(i, N+1){
        if(visited[i])continue;

        dist[i] = 0;
        visited[i] = true;
        bool ok = dfs(G, dist, i, visited);
        // cout << i << ", " << ok << endl;
        if(ok == false){
            no();
            return 0;
        }
    }

    yes();
    return 0;
}