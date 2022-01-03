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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> Aij(H, vector<int>(W, -1));

    REP(i, H){
        REP(j, W){
            cin >> Aij[i][j];
        }
    }

    vector<vector<int>> Bij(H, vector<int>(W, -1));
    vector<int> RowSums(H);
    vector<int> ColSums(W);

    REP(i, H){
        LL val = 0;
        REP(j, W){
            if(Aij[i][j] == -1){continue;}
            val += Aij[i][j];
        }
        RowSums[i]=val;
    }


    REP(j, W){
        LL val = 0;
        REP(i, H){
            if(Aij[i][j] == -1){continue;}
            val += Aij[i][j];
        }
        ColSums[j]=val;
    }

    REP(i, H){
        REP(j, W){
            if(Aij[i][j] == -1){continue;}
            Bij[i][j] = ColSums[j] + RowSums[i] - Aij[i][j];
        }
    }

    REP(i, H){
        REP(j, W){
            if(Aij[i][j] == -1){
                cout << " " << " ";
            }else{
                cout << Bij[i][j] << " ";
            }
        }
        cout << "" << endl;
    }

    return 0;

}