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

LL Q = 998244353LL;
map<LL, LL> val_map;

LL dfs(LL val){
    if(val_map.find(val) != val_map.end()){
        return val_map[val];
    }

    LL q = val / 2LL;
    LL r = val % 2LL;
    LL next_val = (dfs(q) * dfs(q + r)) % Q;
    val_map[val] = next_val;
    return next_val % Q;
}

int main(){
    LL X;
    cin >> X;

    val_map[1LL] = 1LL;
    val_map[2LL] = 2LL;
    val_map[3LL] = 3LL;
    val_map[4LL] = 4LL;

    LL ans = dfs(X);
    out(ans);

    return 0;
}