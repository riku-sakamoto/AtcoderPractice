#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N, vector<int>(0));
    int indeg[N]{};
    REP(i, N){
        indeg[i] = 0;
    }
    REP(i, M){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        indeg[b] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> que;
    REP(i, N){
        if(indeg[i] == 0){
            que.push(i);
        }
    }

    vector<int> ans;
    while(!que.empty()){
        int val = que.top();
        que.pop();
        ans.push_back(val);

        for(auto v : graph[val]){
            indeg[v] -= 1;
            if(indeg[v] == 0){
                que.push(v);
            }
        }
    }

    if(ans.size() != N){
        cout << -1 << endl;
        return 0;
    }    

    REP(i, N){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}