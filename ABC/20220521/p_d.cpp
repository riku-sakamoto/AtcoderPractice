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

LL dfs(vector<int>& A, vector<vector<int>>& idx_vecs, int idx, int k){
    if(k == 0){
        auto idx_vec = idx_vecs[A[idx]];
        int n_idx = lower_bound(ALL(idx_vec), idx) - idx_vec.begin();
    }

}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)cin >> A[i];

    return 0;
}