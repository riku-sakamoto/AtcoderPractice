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
    vector<LL> Xi(N);
    vector<LL> Yi(N);

    REP(i, N){
        cin >> Xi[i] >> Yi[i];
    }

    sort(ALL(Xi));
    sort(ALL(Yi));

    int n = N / 2;

    LL x = Xi[n];
    LL y = Yi[n];

    LL ans = 0;
    REP(i, N){
        ans += abs(Xi[i] - x);
        ans += abs(Yi[i] - y);
    }

    cout << ans << endl;
    return 0;    
}