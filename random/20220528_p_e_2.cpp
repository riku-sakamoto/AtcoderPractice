#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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


using mint = modint998244353;

mint calcSum(vector<mint>& dp_sum, int l, int r, int M){
    if(l > r){
        return 0LL;
    }

    int _l = max({0, l-1});
    int _r = min({M, r});

    return (dp_sum[_r]  - dp_sum[_l]);

}


int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<mint> dp(M+1, 0LL);

    FOR(j, 1, M+1){
        dp[j] = 1LL;
    }

    REP(i, N-1){
        vector<mint> dp_next(M+1, 0LL);

        vector<mint> dp_sum(M+1, 0LL);
        FOR(j, 1, M+1){
            dp_sum[j] = (dp[j] + dp_sum[j - 1]);
        }

        if(K != 0){
            FOR(j, 1, M+1){
                dp_next[j] = calcSum(dp_sum, 1, j-K, M) + calcSum(dp_sum, j+K, M, M) ;
            }
        }else{
            FOR(j, 1, M+1){
                dp_next[j] = calcSum(dp_sum, 1, M, M);
            }
        }

        dp = dp_next;
    }


    mint ans = 0;
    FOR(j, 1, M+1){
        ans += dp[j];
    }

    cout << ans.val() << endl;

    return 0;
}