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

int main(){
    int N;
    cin >> N;
    vector<LL> A(N, 0);
    REP(i, N){
        cin >> A[i];
    }
    vector<LL> Sums(N);
    LL tmp_sum = 0;
    REP(i, N){
        tmp_sum += A[i];
        Sums[i] = tmp_sum;
    }

    LL max_sum = 0;
    vector<LL> maxSums(N);
    REP(i, N){
        chmax(max_sum, Sums[i]);
        maxSums[i] = max_sum;
    }

    LL ans = 0;
    LL now = 0;
    REP(i, N){
        LL max_step = now + maxSums[i];
        chmax(ans, max_step);
    
        now += Sums[i];
    }

    cout << ans << endl;
    return 0;
}