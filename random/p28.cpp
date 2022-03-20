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

    int maxN = 1002;
    vector<vector<int>>Area(maxN, vector<int>(maxN, 0));
    REP(i, N){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        Area[ly][lx] += 1;
        Area[ly][rx] += -1;
        Area[ry][lx] += -1;
        Area[ry][rx] += 1;
    }



    REP(i, maxN){
        REP(j, maxN){
            if(j==0)continue;
            Area[i][j] += Area[i][j-1];
        }
    }

    REP(j, maxN){
        REP(i, maxN){
            if(i==0)continue;
            Area[i][j] += Area[i-1][j];
        }
    }

    // REP(i, 5){
    //     REP(j, 5){
    //         cout << Area[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> ans(N+1, 0);
    REP(i, maxN){
        REP(j, maxN){
            ans[Area[i][j]] += 1;
        }
    }

    FOR(i, 1, N+1){
        cout << ans[i] << endl;
    }

    return 0;
}