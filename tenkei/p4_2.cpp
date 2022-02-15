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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> Aij(H, vector<int>(W));

    REP(i, H){
        REP(j, W){
            cin >> Aij[i][j];
        }
    }

    vector<int> Sums_row(H, 0);
    vector<int> Sums_col(W, 0);

    REP(i, H){
        int tmp = 0;
        REP(j, W){
            tmp += Aij[i][j];
        }
        Sums_row[i] = tmp;
    }

    REP(j, W){
        int tmp = 0;
        REP(i, H){
            tmp += Aij[i][j];
        }
        Sums_col[j] = tmp;
    }

    REP(i, H){
        REP(j, W){
            int ans = Sums_row[i] + Sums_col[j] - Aij[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;


}
