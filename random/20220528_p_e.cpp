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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}


LL LARGE = 998244353LL;

LL calcSum(vector<LL>& dp_sum, int l, int r, int M){
    if(l > r){
        return 0LL;
    }

    int _l = max({0, l-1});
    int _r = min({M, r});

    LL R_VAL = dp_sum[_r];
    while(R_VAL < dp_sum[_l]){
        R_VAL += LARGE;
    }

    return (R_VAL  - dp_sum[_l]) % LARGE;

}


int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<LL> dp(M+1, 0LL);

    FOR(j, 1, M+1){
        dp[j] = 1LL;
    }

    REP(i, N-1){
        vector<LL> dp_next(M+1, 0LL);

        vector<LL> dp_sum(M+1, 0LL);
        FOR(j, 1, M+1){
            dp_sum[j] = (dp[j] % LARGE + dp_sum[j - 1] % LARGE) % LARGE;
        }

        if(K != 0){
            FOR(j, 1, M+1){
                // dp_next[j] =  (dp_next[j] + dp_sum[max({j-K, 0})]) % LARGE;
                // dp_next[j] =  (dp_next[j] + dp_sum[M] - dp_sum[min({j+K-1, M})]) % LARGE;
                dp_next[j] = (calcSum(dp_sum, 1, j-K, M) % LARGE + calcSum(dp_sum, j+K, M, M) % LARGE) % LARGE;
            }
        }else{
            FOR(j, 1, M+1){
                dp_next[j] = (calcSum(dp_sum, 1, M, M)) % LARGE;
            }
        }

        dp = dp_next;
    }


    LL ans = 0;
    FOR(j, 1, M+1){
        ans = (ans % LARGE + dp[j] % LARGE) % LARGE;
    }

    cout << ans << endl;

    return 0;
}