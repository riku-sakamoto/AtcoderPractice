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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

using namespace atcoder;
using mint = modint1000000007;

int main(){
    LL N_, M_;
    cin >> N_ >> M_;

    if(abs(N_ - M_) >= 2){
        cout << 0 << endl;
        return 0;
    }

    mint ans = mint(1LL);
    REP(i, N_){
        ans *= mint(i + 1);
    }
    REP(i, M_){
        ans *= mint(i + 1);
    }

    if(N_ == M_){
        ans *= mint(2LL);
    }

    cout << ans.val() << endl;
    return 0;
}