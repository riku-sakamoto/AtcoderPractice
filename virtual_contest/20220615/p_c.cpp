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

LL pow(LL k, int n){
    LL val = 1;
    REP(i, n){
        val *= k;
    }
    return val;
}

LL func(LL val, string val_S){
    LL ans = 0;
    int n = val_S.size() - 1; 
    REP(i, val_S.size()){
        int tmp = val_S[n - i] - '0';
        ans += pow(val, i) * tmp;
    }
    return ans;
}

int main(){
    LL A;
    cin >> A;

    LL val = 10;
    while(val < 100000){
        LL calcVal = func(val, to_string(val));
        if(calcVal==A){
            out(val);
            return 0;
        }
        ++val;
    }

    out(-1);

    return 0;
}