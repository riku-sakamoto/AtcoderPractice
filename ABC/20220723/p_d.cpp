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

int main(){
    int N, M;
    cin >> N >> M;
    vector<LL> X(N, 0);
    REP(i, N)cin >> X[i];
    vector<pair<int, LL>> Bonus(M);
    REP(i, M){
        int c;
        LL y;
        cin >> c >> y;
        Bonus[i] = {c, y};
    }

    //counter to point
    vector<LL> dp(N+1, 0);

    REP(i, N){
        vector<LL> nw_dp(N+1, 0);

        REP(j, N + 1){
            if (j == N) continue;

            if(j != 0 && dp[j] == 0) continue;

            // omote
            nw_dp[j + 1] = dp[j] + X[i];

            // ura
            nw_dp[0] = max({nw_dp[0], dp[j]});
        }

        REP(j, M){
            int c = Bonus[j].first;
            LL y = Bonus[j].second;
            if (nw_dp[c] != 0){
                nw_dp[c] += y;
            }
        }

        dp = nw_dp;

        // REP(i, N){
        //     cout << dp[i] << ", ";
        // }
        // cout << endl;

    }

    LL ans = 0;
    REP(i, N+1){
        chmax(ans, dp[i]);
    }

    out(ans);
    return 0;
}
