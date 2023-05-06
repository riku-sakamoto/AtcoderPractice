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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

using mint = modint1000000007;


int main(){
    int N, M;
    cin >> N >> M;
    set<int> a;
    REP(i, M){
        int _a;
        cin >> _a;
        a.insert(_a);
    }

    vector<mint> dp(N + 1);
    dp[0] = mint(1LL);
    REP(i, N){
        if(a.find(i + 1) == a.end()){
            dp[i+1] += dp[i];
        }
        if(i == N - 1){
            continue;
        }

        if(a.find(i + 2) == a.end()){
            dp[i+2] += dp[i];
        }
    }

    mint ans = dp[N];
    out(ans.val());
    return 0;
}