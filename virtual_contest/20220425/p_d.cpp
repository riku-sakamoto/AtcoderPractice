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
    int N, M;
    cin >> N >> M;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];

    vector<vector<int>> Edges(N);
    REP(i, M){
        int x, y;
        cin >> x >> y;
        Edges[x-1].push_back(y-1);
    }
    
    vector<pair<LL, LL>> Points(N, {0, 0});
    REP(i, N){
        Points[i] = {A[i], -1000000000};
    }

    REP(x, N){
        pair<LL, LL> from = Points[x];
        
        for(auto y: Edges[x]){
            pair<LL, LL> now = Points[y];

            LL profit = A[y] - from.first;
            // cout << x << ", " << y << ", " << profit << endl;

            if(now.second < profit){
                now.second = profit;
            }

            // Buy
            if(now.first > from.first){
                now.first = from.first;
            }

            Points[y] = now;

        }
    }
    
    LL ans = -1000000000;
    REP(i, N){
        pair<LL, LL> now = Points[i];
        // cout << now.first << ", " << now.second << endl; 
        chmax(ans, now.second);
    }
    cout << ans << endl; 
    return 0;
}