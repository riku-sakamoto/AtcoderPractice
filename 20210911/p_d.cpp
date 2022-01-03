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
    vector<pair<int, int>> Points(N);
    
    REP(i, N){
        int x, y;
        cin >> x >> y;
        // Points.push_back(make_pair(x, y));
        Points[i].first = x;
        Points[i].second = y;
    }

    sort(ALL(Points));

    LL ans = 0;
    REP(i, N){
        REP(j, N){
            pair<int, int> pi = Points[i];
            pair<int, int> pj = Points[j];

            if(pj.first > pi.first && pj.second > pi.second){
                int xi = pi.first;
                int yi = pi.second;
                int xj = pj.first;
                int yj = pj.second;
                bool isK = binary_search(ALL(Points), make_pair(xi, yj));
                bool isL = binary_search(ALL(Points), make_pair(xj, yi));
                if(isK && isL){
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
    
}