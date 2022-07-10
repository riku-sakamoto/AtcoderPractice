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

int main(){
    double a, b;
    double d;
    cin >> a >> b >> d;
    // const double pi = 3.141592653589793;
    double theta = (d / 180.0) * M_PI;
    double x = a * cos(theta) - b * sin(theta);
    double y = a * sin(theta) + b * cos(theta);
    // cout << theta << "," << cos(theta) << ", " << sin(theta) << endl;

    cout << fixed << setprecision(15) << x << " " << y << endl;
    return 0;
}