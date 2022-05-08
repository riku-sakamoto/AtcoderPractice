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

// Dijkstra Methods O(V2)

// 4 6 0
// 0 1 2
// 0 2 1
// 0 3 1
// 1 2 2 
// 1 3 5
// 2 3 4

const LL INF = 1LL << 60;

struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main(){
    // N: num of nodes
    // M: num of edges
    // s: start
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N);
    REP(i, M){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<bool> used(N, false);
    vector<LL> dist(N, INF);

    dist[s] = 0;

    REP(itr, N){
        LL min_dist = INF;
        int min_v = -1;

        // 未探索のノードの内最小距離のノードを探す
        REP(i, N){
            if(!used[i] && dist[i] < min_dist){
                min_dist = dist[i];
                min_v = i;
            }
        }

        if(min_v == -1)break;

        // min_vを始点とした各辺を緩和する
        for(auto e: G[min_v]){
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true;
    }


    REP(i, N){
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}