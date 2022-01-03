#define _GLIBCXX_DEBUG
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

// vector<int> G[1 << 18];
// vector<int> H[1 << 18];

vector<int> I;

int dfs(vector<vector<int>> G, ){

}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);
    vector<vector<int>> H(N+1);
    
    vector<int> A(M);
    vector<int> B(M);
    REP(i,M){
        cin>>A[i]>>B[i];
        G[A[i]].push_back(B[i]);
        H[B[i]].push_back(A[i]);
    }
    
    REP(i,N+1){
        for(int j : G[i]){
            cout << j;
        }
        cout << endl;
    }

    
    return 0;
    
}