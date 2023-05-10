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
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else{return false;};}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

const LL INF = 1LL << 60;

struct Edge {
    int to;
    LL k;
    LL t;
    Edge(int to, LL k, LL t): to(to), k(k), t(t) {}
};

using Graph = vector<vector<Edge>>;


int main(){
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    --X;
    --Y;
    Graph G(N);
    REP(i, M){
        int a, b;
        LL T, K;
        cin >> a >> b >> T >> K;
        --a;
        --b;
        G[a].push_back(Edge(b, K, T));
        G[b].push_back(Edge(a, K, T));
    }

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> que;
    vector<LL> dist(N, INF);
    que.push({0, X});
    dist[X] = 0;

    while(!que.empty()){
        // 未探索のノードの内最小距離のノードを探す
        auto p = que.top(); que.pop();
        int min_v = p.second;
        LL d = p.first;

        // 確定済みのノードに関する情報が入る可能性がある．usedリストを使用しないため．
        if(d > dist[min_v])continue;

        // min_vを始点とした各辺を緩和する
        for(auto e: G[min_v]){
            auto now = dist[min_v];
            if(now % e.k == 0){
                if(chmin(dist[e.to], now + e.t)){
                    que.push({dist[e.to], e.to});
                }
            }else{
                LL r = e.k - now % e.k;
                if(chmin(dist[e.to], now + e.t + r)){
                    que.push({dist[e.to], e.to});
                }
            }
        }
    }

    auto ans = dist[Y];
    if(ans == INF){
        out(-1);
    }else{
        out(ans);
    }
    return 0;
}