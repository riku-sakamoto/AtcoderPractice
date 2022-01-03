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
    using P = pair<LL, LL>;
    LL D;
    cin >> N >> D;
    vector<pair<LL, LL>> walls;
    REP(i, N){
        LL l, r;
        cin >> l >> r;
        walls.push_back({l, r});
    }

    sort(ALL(walls), [](P& a, P& b){return a.second < b.second; });

    LL ans = 1;
    LL start = walls[0].second;
    REP(i, N){
        LL l = walls[i].first;
        LL r = walls[i].second;
        if(l >= start + D){
            ans+=1;
            start = r;
        }
    }

    cout << ans << endl;
    return 0;
}