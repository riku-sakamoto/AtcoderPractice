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


class Edge {
    public:
        Edge(int r, int f, int t, int c);
        int rev; // 逆辺（to -> from）がG[to]の中で何番目か
        int from;
        int to;
        int cap; // capacity

};

Edge::Edge(int r, int f, int t, int c){
    this->rev = r;
    this->from = f;
    this->to = t;
    this->cap = c;
}


class Graph{
    private:
        vector<vector<Edge>> edge_lists;
    public:
        Graph(int N);
        size_t size();
        vector<Edge> &operator [] (int i){
            return edge_lists[i];
        };
        Edge redge(const Edge &e);
        void run_flow(Edge &e, int f);
        void add_edge(int from, int to, int cap);

};

Graph::Graph(int N){
    this->edge_lists = vector<vector<Edge>>(N);
}

size_t Graph::size(){
    return this->edge_lists.size();
}

Edge Graph::redge(const Edge &e){
    return this->edge_lists[e.to][e.rev];
}

void Graph::run_flow(Edge &e, int f){
    e.cap -= f;
    this->redge(e).cap -= f;
}

// from から toへ辺をはる．このとき，toからfromへもcapが０の辺をはっておく．
void Graph::add_edge(int from, int to, int cap){
    int fromrev = this->edge_lists[from].size();
    int torev = this->edge_lists[to].size();

    this->edge_lists[from].push_back(Edge(torev, from, to, cap));
    this->edge_lists[to].push_back(Edge(fromrev, to, from, 0));

}

class FordFulkerson{
    private:
        const int INF = 1 << 30;
        vector<bool> seen;
        // 残余グラフ上でs-tパスを見つける (DFS)
        // return: s-tパス上の容量の最小値（見つからなければ０）
        // f: ｓからｖへ到達した過程の各辺容量の最小値
        int fodfs(Graph &G, int v, int t, int f);

    public:
        FordFulkerson();

        int solve(Graph &G, int s, int t);
};

FordFulkerson::FordFulkerson(){}

int FordFulkerson::fodfs(Graph &G, int v, int t, int f){
    if(v == t){return f;}

    this->seen[v] = true;
    for(auto &e : G[v]){
        if(this->seen[e.to]) continue;

        // 容量０は無視（実際には存在しないため）
        if(e.cap == 0)continue;

        int flow = fodfs(G, e.to, t, min({f, e.cap}));
        if(flow == 0)continue;

        G.run_flow(e, flow);

        return flow;
    }

    return 0;
}

int FordFulkerson::solve(Graph &G, int s, int t){
    int res = 0;

    while(true){
        this->seen = vector<bool>(G.size(), false);
        int flow = this->fodfs(G, s, t, this->INF);

        if(flow == 0){
            return res;
        }

        res += flow;
    }

    return 0;
}


int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);

    REP(i, M){
        int u, v, c;
        cin >> u >> v >> c;

        G.add_edge(u, v, c);
    }

    FordFulkerson ff;

    int s = 0;
    int t = N - 1;
    int ans = ff.solve(G, s, t);
    cout << ans << endl;
    return 0;
}