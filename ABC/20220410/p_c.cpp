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

// vector<int> dfs(int next_n, vector<int>& elems){
//     elems.push_back(next_n);
// }

void dfs_void(int n){
    if (n == 1){
        cout << 1 << " ";
    }else{
        dfs_void(n - 1);
        cout << n << " ";
        dfs_void(n - 1);
    }
}

int main(){
    int N;
    cin >> N;

    dfs_void(N);
    cout << endl;
    return 0;
}