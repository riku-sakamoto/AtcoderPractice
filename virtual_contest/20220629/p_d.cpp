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

using namespace atcoder;
using mint = modint1000000007;

mint comb(LL n, int k){
    mint ans = 1;
    REP(i, k){
        ans = (ans * mint(n - i)) ;
    }
    REP(i, k){
        ans = ans / mint(i + 1);
    }
    return ans;
}


int main(){
    LL n;
    int a, b;
    cin >> n >> a >> b;

    mint num_all = mint(2).pow(n);

    mint comb_a = comb(n, a);
    mint comb_b = comb(n, b);

    mint ans = num_all - 1 - comb_a - comb_b;
    // mint ans = num_all;
    cout << ans.val() << endl;
    return 0;
}