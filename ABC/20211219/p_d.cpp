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

vector<pair<int, int>> Dij = {{1, 0},{0, 1}};
int H;
int W;

int dfs(vector<vector<char>>& Cij, pair<int, int> now, int count, vector<vector<bool>>& visited){
    int i = now.first;
    int j = now.second;
    visited[i][j] = true;

    priority_queue<int> counts;
    counts.push(count);
    for(auto dij: Dij){
        int nexti = i + dij.first;
        int nextj = j + dij.second;
        if(nexti < 0 || nexti >= H || nextj < 0 || nextj >= W) continue;
        if(visited[nexti][nextj]) continue;
        if(Cij[nexti][nextj] == '#')continue;
        // cout << nexti << "," << nextj << endl;
        int _count = dfs(Cij, {nexti, nextj}, count+1, visited);
        counts.push(_count);
    }
    return counts.top();
}

int main(){
    cin >> H >> W;

    vector<vector<char>> Cij(H, vector<char>(W, '.'));
    REP(i, H){
        REP(j, W){
            cin >> Cij[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    int ans = dfs(Cij, {0,0}, 1, visited);

    cout << ans << endl;
    return 0;

}