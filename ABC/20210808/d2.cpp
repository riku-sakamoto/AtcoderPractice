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

vector<vector<int>> G;
vector<int>ans;


void dfs(int crr, int pre){
    ans.push_back(crr);
    for(int nxt:G[crr]){
        if(nxt!=pre){
            dfs(nxt,crr);
            ans.push_back(crr);
        }
    }
}

int main(){
    int N;
    cin >> N;

    G.resize(N+1);
    REP(i,N-1){
        int ai, bi;
        cin >> ai >> bi;
        G[ai].push_back(bi);
        G[bi].push_back(ai);
    }

    REP(i,N+1){
        sort(ALL(G[i]));
    }

    dfs(1, -1);

    REP(i,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}