#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const double pi=3.141592653589793;

int main(){
    double T, L, X, Y;
    cin >> T;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    vector<LL> E(Q);
    REP(i,Q)cin>>E[i];

    cout << fixed << setprecision(12);
    REP(i,Q){
        LL e = E[i];
        double y = - L/2.0 * sin(2.0*pi*e/T);
        double z = L/2.0 * (1.0 - cos(2.0*pi*e/T));

        double L = sqrt(X*X + (Y-y)*(Y-y));

        double ans;
        if(L < 1E-5){
            ans = 90;
        }else{
            ans = atan(z/L) * 180.0 / pi;
        }

        cout << ans << endl;


    }
    return 0;
    
}