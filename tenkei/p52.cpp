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
    vector<vector<int>> Aij(N, vector<int>(6, 0));
    REP(i, N){
        REP(j, 6){
            cin >> Aij[i][j];
        }
    }

    LL Q = 1E9 + 7;
    LL ans = 1;
    REP(i, N){
        LL _sum = 0;
        REP(j, 6){
            _sum = (_sum + ans * Aij[i][j] % Q) % Q;
        }
        ans = _sum;
    }

    cout << ans << endl;
    return 0;
    
}