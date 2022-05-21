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

int main(){
    int N;
    cin >> N;
    vector<pair<LL, LL>> xy(N);
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        xy[i] = pair<LL, LL>(x, y);
    }
    
    vector<vector<int>> dp(N, vector<int>());

    REP(i, N){
        dp[i]
    }
    
    REP(i, N){
        cout << xy[i].first << " " << xy[i].second << endl;
    }

    return 0;
}