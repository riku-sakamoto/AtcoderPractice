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

double getPoint(LL X0, LL Y0, LL X, LL Y){
    if (Y == Y0){
        
    }

}

int main(){
    LL W, H, X, Y;
    cin >> W >> H;
    cin >> X >> Y;

    LL S = W * H;
    LL S1 = min({X * H, S - X * H});
    LL S2 = min({Y * W, S - Y * W});

    // (0, 0)を通る
    double x0 = X * H / Y;
    double S3 = x0 * H / 2;
    S3 = min({S3, S - S3});

    double x1 = 

    return 0;
}