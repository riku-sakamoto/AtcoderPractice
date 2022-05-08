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

    bool is_negative_loop = false;
    bool is_update = false;
    vector<LL> dist(N, INF);
    dist[s] = 0;
    REP(itr, N){
        is_update = false;
        REP(i, N){
            if(dist[i] == INF)continue;
            for(auto e: G[i]){
                LL tmp = dist[i] + e.w;
                if(dist[e.to] > tmp){
                    chmin(dist[e.to], tmp);
                    is_update = true;
                }
            }
        }
    }

    if(is_update == true){
        is_negative_loop = true;
    }

    if(is_negative_loop){
        cout << "Negative Loop" << endl;
        return 0;
    }

    REP(i, N){
        cout << i << ": " << dist[i] << endl;
    }
    return 0;
}