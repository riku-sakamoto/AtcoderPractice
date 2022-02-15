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

pair<int, int> bfs(int pos, vector<vector<int>>& routes, vector<bool>& visited){
    queue<pair<int, int>> que;
    int max_length = 0;
    int last_pos = pos;
    que.push({pos, 0});
    while(!que.empty()){
        auto tmp = que.front(); que.pop();
        visited[tmp.first] = true;
        last_pos = tmp.first;
        chmax(max_length, tmp.second);
        // cout << tmp.first << ", " << tmp.second << endl;
        for(int p: routes[tmp.first]){
            if(visited[p] == true) continue;
            que.push({p, tmp.second + 1});
        }
    }

    return {max_length, last_pos};
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> Routes(N+1);

    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        Routes[a].push_back(b);
        Routes[b].push_back(a);
    }

    int ans = 0;
    vector<bool> visited(N+1, false);
    auto tmp_ans = bfs(1, Routes, visited);
    // ans += tmp_ans.first;

    REP(i, N+1) visited[i] = false;
    tmp_ans = bfs(tmp_ans.second, Routes, visited);
    ans += tmp_ans.first + 1;
    
    cout << ans << endl;
    return 0;


}