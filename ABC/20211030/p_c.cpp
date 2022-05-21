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
    int N, M;
    cin >> N >> M;

    vector<vector<LL>> Bij(N, vector<LL>(M, 0));
    REP(i, N){
        REP(j, M){
            cin >> Bij[i][j];
        }
    }

    vector<vector<pair<LL,LL>>> indexes(N, vector<pair<LL, LL>>(M));
    REP(i, N){
        REP(j, M){
            if(Bij[i][j] % 7 == 0){ 
                LL val = Bij[i][j] / 7;
                indexes[i][j] = pair<LL, LL>(val, 7); 
            }else{
                LL val2 = Bij[i][j] % 7;
                LL val1 = (Bij[i][j] - val2) / 7 + 1;
                indexes[i][j] = pair<LL, LL>(val1, val2); 
            }
        }
    }

    // REP(i, N){
    //     REP(j, M){
    //         cout << indexes[i][j].first <<"," << indexes[i][j].second << " ";
    //     }
    //     cout << endl;
    // }


    REP(i, N){
        FOR(j, 1, M){
            if(indexes[i][j].first - indexes[i][j-1].first != 0 || indexes[i][j].second - indexes[i][j-1].second != 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    FOR(i, 1, N){
        REP(j, M){
            if(indexes[i][j].first - indexes[i-1][j].first != 1 || indexes[i][j].second - indexes[i-1][j].second != 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
    


}