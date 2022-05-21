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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


bool dfs(vector<vector<int>>& routes, int val, int pre, vector<bool>& visited){
    visited[val] = true;
    // cout << "val " << val << ", pre: " << pre << "routes[val]" << routes[val].size() << endl;
    if(routes[val].size() == 1 && routes[val][0] == pre){
        return true;
    }

    bool ok = false;
    int count = 0;
    for(int next: routes[val]){
        if(visited[next] == true)continue;
        ok = dfs(routes, next, val, visited);
    }

    return ok;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> routes(N+1, vector<int>());
    int a, b;    
    REP(i, M){
        cin >> a >> b;
        routes[a].push_back(b);
        routes[b].push_back(a);
    }

    vector<bool> visited(N+1, false);

    bool ans = true;
    FOR(i, 1, N+1){
        // cout << routes[i].size() << endl;
        if(routes[i].size() > 2){
            cout << "No" << endl;
            return 0;
        }
    }

    FOR(i, 1, N+1){
        if(routes[i].size() == 0) continue;
        if(visited[i] == false){

            bool _ok = dfs(routes, i, -1, visited);
            if(_ok == false){
                ans = false;
                break;
            }
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}