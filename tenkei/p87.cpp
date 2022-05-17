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


const LL LARGE_COST = 100000001;

vector<vector<LL>> floyd_warshall(int N, vector<vector<LL>>& routes, LL X){
    vector<vector<LL>> dp(N, vector<LL>(N, LARGE_COST));

    // Initial Condition
    REP(i, N){
        REP(j, N){
            if(routes[i][j] == -1){
                dp[i][j] = X;
            }else{
                dp[i][j] = routes[i][j];
            }
        }
    }

    // DP
    REP(k, N){
        REP(i, N){
            REP(j, N){
                dp[i][j] = min({dp[i][j], dp[i][k] + dp[k][j]});
            }
        }
    }

    return dp;
}


LL findK(int N, vector<vector<LL>>& routes, LL X, LL P){
    vector<vector<LL>> dp = floyd_warshall(N, routes, X);
    LL num = 0;
    REP(i, N){
        FOR(j, i+1, N){
            if(dp[i][j] <= P){
                ++num;
            }
        }
    }
    return num;
}

LL getBorder(LL val, int N, vector<vector<LL>>& routes, LL P){
    LL left = 1LL;
    LL right = 5000000000LL;
    LL minx = 5000000000LL;

    while(right - left > 1LL){
        LL mid = (left + right) / 2LL;
        LL k = findK(N, routes, mid, P);
        // cout << k << endl;
        if(k <= val){
            right = mid;
            chmin(minx, right);
        }else{
            left = mid;
        }
    }

    return minx;
}

int main(){
    int N;
    LL P, K;
    cin >> N >> P >> K;
    vector<vector<LL>> A(N, vector<LL>(N, 0));
    REP(i, N){
        REP(j, N){
            cin >> A[i][j];
        }
    }

    // LL k = findK(N, A, 3, P);
    // cout << k << endl;

    // 条件を満たす経路数がKより小さいときのX
    LL num1 = getBorder(K, N, A, P);
    // cout << num1 << endl;

    // 条件を満たす経路数がK-1より小さいときのX
    LL num2 = getBorder(K-1, N, A, P);
    // cout << num2 << endl;

    // if(num2 == 5000000000LL){
    //     cout << "Infinity" << endl;
    //     return 0;
    // }

    // if(num1 == 5000000000LL){
    //     cout << "Infinity" << endl;
    //     return 0;
    // }

    if(num2 - num1 >= 2000000000LL){
        cout << "Infinity" << endl;
        return 0;
    }

    LL ans = num2 - num1;
    cout << ans << endl;

    return 0;
}