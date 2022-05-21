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
    int H, W;
    cin >> H >> W;
    int R, C;
    cin >> R >> C;
    int ans = 0;
    queue<pair<int, int>> que;
    que.push({R, C+1});
    que.push({R, C-1});
    que.push({R+1, C});
    que.push({R-1, C});
    while(!que.empty()){
        auto p = que.front(); que.pop();
        if(p.first >= 1 && p.first <= H && p.second >= 1 && p.second <= W){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}