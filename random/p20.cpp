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

LL powCalc(int x, int n){
    LL ans = 1;
    REP(i, n){
        ans *= x;
    }
    return ans;
}


int main(){
    LL a;
    int b,c;
    cin >> a;
    cin >> b >> c;

    LL m = powCalc(c, b);
    if(a < m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}