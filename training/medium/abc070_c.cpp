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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

LL gcd(LL val1, LL val2){
    LL val_min = min({val1, val2});
    LL val_max = max({val1, val2});
    if(val_min == 0){
        return val_max;
    }

    return gcd(val_min, val_max % val_min);
}

LL lcm(LL val1, LL val2){
    LL _gcd = gcd(val1, val2);
    LL val = (val1 / _gcd) * (val2 / _gcd) * _gcd;
    return val;
}

int main(){
    int N;
    cin >> N;
    vector<LL> T(N);
    REP(i, N){
        cin >> T[i];
    }

    LL ans = 1LL;
    REP(i, N){
        ans = lcm(T[i], ans);
    }
    out(ans);
    return 0;
}