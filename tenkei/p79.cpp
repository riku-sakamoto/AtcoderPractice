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

    vector<vector<int>> Aij(H, vector<int>(W, 0));
    vector<vector<int>> Bij(H, vector<int>(W, 0));

    REP(i, H){
        REP(j, W){
            cin >> Aij[i][j];
        }
    }

    REP(i, H){
        REP(j, W){
            cin >> Bij[i][j];
        }
    }
    
    LL count = 0;
    REP(i, H-1){
        REP(j, W-1){
            if(Aij[i][j] == Bij[i][j])continue;
            int diff = Bij[i][j] - Aij[i][j];
            count += abs(diff);

            Aij[i][j] += diff;
            Aij[i+1][j] += diff;
            Aij[i][j+1] += diff;
            Aij[i+1][j+1] += diff;
        }
    }
    

    bool isSame = (Aij == Bij);
    // REP(i, H){
    //     REP(j, W){
    //         if(Aij[i][j] != Bij[i][j]){
    //             isSame = false;
    //             break;
    //         }
    //     }
    // }

    if(isSame){
        cout << "Yes" << endl;
        cout << count << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;

}