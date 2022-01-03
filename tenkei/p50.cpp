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
    int N, L;
    cin >> N >> L;
    LL Q = 1E9 + 7;

    vector<LL> dp(N+1, 0);
    dp[0] = 1;

    FOR(i, 1, N+1){
        int j = i - L;

        if(j < 0){
            dp[i] = (dp[i - 1]) % Q;
        }else{
            dp[i] = (dp[j] + dp[i - 1]) % Q;
        }
    }

    cout << dp[N] << endl;
    return 0;

}
