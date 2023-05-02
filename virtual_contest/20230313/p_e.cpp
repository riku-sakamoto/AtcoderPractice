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




void dfs(int start, int parent, vector<vector<int>>& graph, vector<int>& belongs, vector<bool>& is_cycle){
    for (auto x: graph[start]){
        if (belongs[x] != -1){
            continue;
        }
        if (is_cycle[x]){
            continue;
        }
        belongs[x] = parent;
        dfs(x, parent, graph, belongs, is_cycle);
    }
}

int main(){
    int N;
    cin >> N;
    // 次数
    vector<int> degree(N, 0);
    // node(idx) to nodes
    vector<vector<int>> graph(N, vector<int>());
    vector<bool> is_cycle(N, true);
    // belong
    vector<int> belongs(N, -1);

    REP(i, N){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        degree[u] += 1;
        degree[v] += 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> one_deg_nodes;
    REP(i, N){
        if(degree[i] == 1){
            one_deg_nodes.push(i);
        }
    }

    while(!one_deg_nodes.empty()){
        auto node = one_deg_nodes.front(); one_deg_nodes.pop();
        is_cycle[node] = false;
        degree[node] -= 1;
        for(auto to: graph[node]){
            degree[to] -= 1;

            if (degree[to] == 1){
                one_deg_nodes.push(to);
            }
        }
    }

    REP(i, N){
        if (is_cycle[i]){
            belongs[i] = i;
            dfs(i, i, graph, belongs, is_cycle);
        }
    }

    queue<string> que;
    int Q;
    cin >> Q;
    REP(i, Q){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (belongs[x] == belongs[y]){
            que.push("Yes");
        }else{
            que.push("No");
        }
    }

    while(!que.empty()){
        auto ans = que.front();
        que.pop();
        cout << ans << endl;
    }
   
    return 0;
}