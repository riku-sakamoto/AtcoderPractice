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
    LL K;
    cin >> K;
    vector<LL> A(N, 0);
    REP(i, N){
       cin >> A[i]; 
    }

    vector<LL> sums(N+1, 0);

    FOR(i, 1, N+1){
        sums[i] = sums[i-1] + A[i-1];
    }

    // sort(ALL(sums));

    // FOR(i, 0, N+1){
    //     cout << sums[i].first << ", " << sums[i].second << endl;
    // }
    // auto comp = [](pair<LL, int> l, pair<LL, int> r){return l.first < r.first;};

    map<LL, LL> mp;
    LL ans = 0;
    // i は右端を表す
    FOR(i, 1, N+1){
        // 一つ前の和を登録
        mp[sums[i-1]]++;
        ans += mp[sums[i]-K];
    }

    cout << ans << endl;
    return 0;
    

}
