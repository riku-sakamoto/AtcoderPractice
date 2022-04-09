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


LL func(LL a, LL b){
    return a *a*a + a*a*b + a*b*b + b*b*b;
}


int main(){
    LL N;
    cin >> N;
    LL ans =  8e18;

    LL max_i = 1e6;
    LL j = 1e6;
    for(LL i = 0; i < max_i; ++i){
        while(j >= 0 && func(i, j) >= N){
            chmin(ans, func(i, j));
            --j;
        }
    }

    cout << ans << endl;
    return 0;
}