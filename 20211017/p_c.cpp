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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int N;
    cin >> N;

    vector<double> A(N);
    vector<double> B(N);
    double sumT = 0;
    REP(i, N){
        cin >> A[i] >> B[i];
        sumT += A[i] / B[i];
    }
    
    double t = 0;
    double ans = 0;
    int i = 0;
    while(t < sumT / 2.0){
        
        double tmp = t + A[i] / B[i];
        if(tmp > sumT / 2.0) break;
        t = tmp;
        ans += A[i];
        i++;
    }

    ans += (sumT / 2.0 - t) * B[i];

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
    
}