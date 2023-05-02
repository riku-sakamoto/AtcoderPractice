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


int gcd(int val1, int val2){
    int val_min = min({val1, val2});
    int val_max = max({val1, val2});
    if(val_min == 0){
        return val_max;
    }

    return gcd(val_min, val_max % val_min);
}

int lcm(int val1, int val2){
    int _gcd = gcd(val1, val2);
    int val = (val1 / _gcd) * (val2 / _gcd) * _gcd;
    return val;
}

int main(){
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int _gcd = gcd(N, M);
    int n = N / _gcd;
    int m = M / _gcd;

    int k = 0;
    while(true){
        int i_n = k * n;
        int j_m = k * m;
        if(i_n >= N){
            break;
        }
        if(j_m >= M){
            break;
        }

        if(S[i_n] != T[j_m]){
            out(-1);
            return 0;
        }
        ++k;
    }

    LL ans = 1LL * n * m * _gcd;
    out(ans);
}