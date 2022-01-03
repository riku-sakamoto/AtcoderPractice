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

int N;

int max_col_value(vector<vector<LL>> Routes, int col){
    LL maxW;
    REP(i, N){
        
    }
}


int main(){
    cin >> N;
    vector<vector<LL>> Routes(N, vector<LL>(N, -1));

    int u, v;
    LL w;
    REP(i, N){
        cin >> u >> v >> w;
        Routes[u-1][v-1] = w;
    }

    vector<LL> maxW(N, 0);
    maxW[0] = Routes[1];
    REP(j, N){
        REP(i, N){
            maxW[j] = max(ALL(Routes[]))
            if(i == j){ break; }
            if(Routes[-1] != -1){
                continue;
            }else{
                Routes[i][j] = max(maxW[j], );
            }
        }
    }
}

