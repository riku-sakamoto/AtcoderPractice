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

    vector<vector<LL>> dp(N, vector<LL>(N, INF));

    // Initial Condition
    REP(i, N){
        for(auto e: G[i]){
            dp[i][e.to] = e.w;
        }
        dp[i][i] = 0;
    }

    // DP
    REP(k, N){
        REP(i, N){
            REP(j, N){
                dp[i][j] = min({dp[i][j], dp[i][k] + dp[k][j]});
            }
        }
    }

    // negative cycle
    bool is_negative_cycle = false;
    REP(i, N){
        if(dp[i][i] < 0){
            is_negative_cycle = true;
        }
    }

    if(is_negative_cycle){
        cout << "Negative Cycle" << endl;
        return 0;
    }


    REP(i, N){
        REP(j, N){
            if(dp[i][j] < INF){
                cout << "From: " << i << ", To: " << j << ", Dist: " << dp[i][j] << endl; 
            }else{
                cout << "From: " << i << ", To: " << j << ", Dist: " << "INF" << endl; 
            }
        }
    }

    return 0;
}