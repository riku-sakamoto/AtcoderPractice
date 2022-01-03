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

LL R = 1E9+7;

int main(){
    int N;
    string S;
    cin >> N >> S;

    vector<vector<LL>> dp(N, vector<LL>(7, 0));
    REP(i, N){
        char c = S[i];
        if(i == 0){
            if(c == 'a'){
               dp[i][0] += 1;
            }
            continue;
        }

        REP(j, 7){
            dp[i][j] = dp[i-1][j];
        }

        if(c == 'a'){
            dp[i][0] = 1 + dp[i-1][0];
        }else if(c == 't'){
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % R;
        }else if(c == 'c'){
            dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % R;
        }else if(c == 'o'){
            dp[i][3] = (dp[i-1][2] + dp[i-1][3]) % R;
        }else if(c == 'd'){
            dp[i][4] = (dp[i-1][3] + dp[i-1][4]) % R;
        }else if(c == 'e'){
            dp[i][5] = (dp[i-1][4] + dp[i-1][5]) % R;
        }else if(c == 'r'){
            dp[i][6] = (dp[i-1][5] + dp[i-1][6]) % R;
        }

    }

    // REP(i, N){
    //     REP(j, 7){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << dp[N-1][6] % R << endl;
    return 0;    
}