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
    int N, K;
    cin >> N >> K;

    vector<LL> A(N);
    vector<LL> B(N);
    vector<LL> Points;

    REP(i, N){
        cin >> A[i] >> B[i];
        Points.push_back(B[i]);
        Points.push_back(A[i] - B[i]);
    }

    sort(ALL(Points), greater<LL>());
    LL ans = 0;
    REP(i, K){
        ans += Points[i];
    }

    cout << ans << endl;
    return 0;
    
}