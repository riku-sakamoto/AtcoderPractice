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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int N, K;

bool dfs(vector<vector<int>>& Tij, int val, int i){
    if (i == N){
        return val == 0;
    }
    REP(j, K){
        int new_val = val ^ Tij[i][j];
        bool detect = dfs(Tij, new_val, i+1);
        if (detect){
            return detect;
        }
    }
    return false;
}


int main(){
    cin >> N >> K;
    vector<vector<int>> Tij(N, vector<int>(K, 0));
    REP(i, N){
        REP(j, K){
            cin >> Tij[i][j];
        }
    }


    int zero_detect = dfs(Tij, 0, 0);
    if (zero_detect){
        out("Found");
    }else{
        out("Nothing");
    }
    
    return 0;
}