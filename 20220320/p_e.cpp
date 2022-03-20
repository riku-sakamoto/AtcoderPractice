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

LL LARGE_VALUE = 998244353;


int main(){
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<vector<int>> edges(N+1);
    REP(i, M){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<vector<LL>> nodesRoutes(N+1);
    FOR(i,0, N+1){
        nodesRoutes[i].push_back(0LL);
        nodesRoutes[i].push_back(0LL);
    }
    nodesRoutes[S][0] = 1LL;

    REP(i, K){
        vector<vector<LL>> next_nodesRoutes(N+1);
        REP(i, N+1){
            next_nodesRoutes[i].push_back(0LL);
            next_nodesRoutes[i].push_back(0LL);
        }

        FOR(j, 1, N+1){
            vector<LL> routes = nodesRoutes[j];
            LL evenRoute = routes[0];
            LL oddRoute = routes[1];

            for(auto k: edges[j]){
                if(k == X){
                    next_nodesRoutes[k][0] = (next_nodesRoutes[k][0] % LARGE_VALUE + oddRoute % LARGE_VALUE) % LARGE_VALUE;
                    next_nodesRoutes[k][1] = (next_nodesRoutes[k][1] % LARGE_VALUE + evenRoute % LARGE_VALUE) % LARGE_VALUE;
                }
                else{
                    next_nodesRoutes[k][0] = (next_nodesRoutes[k][0] % LARGE_VALUE + evenRoute % LARGE_VALUE) % LARGE_VALUE;
                    next_nodesRoutes[k][1] = (next_nodesRoutes[k][1] % LARGE_VALUE + oddRoute % LARGE_VALUE) % LARGE_VALUE;
                }
            }
        }

        nodesRoutes = next_nodesRoutes;

        // REP(i,N){
        //     cout << nodesRoutes[i][0] << ", " << nodesRoutes[i][1] << endl;
        // }
        // cout << "-------" << endl;

    }

    cout << nodesRoutes[T][0] << endl;
    return 0;
}