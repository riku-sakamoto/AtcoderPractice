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


LL pow10(int val){
    LL tmp = 1LL;
    REP(i, val){
        tmp *= 10LL;
    }
    return tmp;
}

int main(){
    LL N;
    cin >> N;

    LL ans = 0LL;
    if(N < pow10(3)){
        ans = 0LL;
    }
    else if(N < pow10(6)){
        ans = N - pow10(3) + 1;
    }
    else if(N < pow10(9)){
        ans = (pow10(6) - pow10(3));
        ans += (N - pow10(6) + 1LL) * 2LL;
    }
    else if(N < pow10(12)){
        ans = (pow10(6) - pow10(3));
        ans += (pow10(9) - pow10(6)) * 2LL;
        ans += (N - pow10(9) + 1LL) * 3LL;
    }
    else if(N < pow10(15)){
        ans = (pow10(6) - pow10(3));
        ans += (pow10(9) - pow10(6)) * 2LL;
        ans += (pow10(12) - pow10(9)) * 3LL;
        ans += (N - pow10(12) + 1LL) * 4LL;
    }
    else{
        ans = (pow10(6) - pow10(3));
        ans += (pow10(9) - pow10(6)) * 2LL;
        ans += (pow10(12) - pow10(9)) * 3LL;
        ans += (pow10(15) - pow10(12)) * 4LL;
        ans += 5LL;
    }

    cout << ans << endl;
    return 0;
}