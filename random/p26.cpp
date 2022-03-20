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

set<int> nums0;
set<int> nums1;


void dfs(int now, int flag, vector<vector<int>>& edges, vector<bool>& visited){
    if(flag == 0) nums0.insert(now);
    if(flag == 1) nums1.insert(now);
    visited[now] = true;

    for(int x: edges[now]){
        if(visited[x]) continue;
        dfs(x, (flag + 1) % 2, edges, visited);
    }
}


int main(){
    int N;
    cin >> N;
    vector<vector<int>> Edges(N+1);
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        Edges[a].push_back(b);
        Edges[b].push_back(a);
    }

    vector<bool> visited(N+1, false);

    dfs(1, 0, Edges, visited);


    set<int> target = (nums0.size() > nums1.size())? nums0 : nums1;

    int i = 0;
    for(auto x: target){
        cout << x << " ";
        i += 1;
        if (i == N / 2) break;
    }
    cout << endl;
    
    return 0;
}