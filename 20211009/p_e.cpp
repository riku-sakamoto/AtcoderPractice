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

vector<int> cnt(1002, 0);

bool dfs(vector<vector<pair<int, int>>>& routes, int now, int past, int goal){
    if(now == goal){
        return true;
    }
    for(pair<int, int> dst: routes[now]){
        // cout << "now: " << now << ", dst: " << dst.first << ", goal" << goal << endl;
        if(dst.first == past){continue;}
        bool result = dfs(routes, dst.first, now, goal);
        if(result == true){
            cnt[dst.second] += 1;
            return true;
        }
    }
    return false;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M, 0);
    REP(i, M)cin >> A[i];

    vector<vector<pair<int, int>>> routes(N+1);
    REP(i, N-1){
        int u, v;
        cin >> u >> v;
        routes[u].push_back({v, i});
        routes[v].push_back({u, i});
    }

    // 帰りがけDFS
    REP(i, M-1){
        // cout << "from " << A[i] << " to " << A[i+1] << endl;
        dfs(routes, A[i], -1, A[i+1]);
    }

    // 桁DP
    int sum=0;
    REP(i, N-1){
        sum += cnt[i]; 
    }
    // cout << sum << endl;
    
    
    const int BASE = sum;
    const LL val = 998244353;
    const int Num = sum + BASE + 1;
    vector<LL> dp(Num, 0);

    dp[0 + BASE] = 1;

    FOR(i, 0, N-1){
        vector<LL> nex(Num, 0);
        REP(j, Num){
            if(dp[j] != 0){
                nex[j + cnt[i]] = (nex[j + cnt[i]] + dp[j]) % val;
                nex[j - cnt[i]] = (nex[j - cnt[i]] + dp[j]) % val;
            }
        }
        dp = nex;
    }

    // REP(j, N-1){
    //     cout << cnt[j] << endl;
    // }
    if(K + BASE >= dp.size()){
        cout << 0 << endl;
    }else{
        cout << dp[K + BASE] << endl;
    }
    return 0;
}