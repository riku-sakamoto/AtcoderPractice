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


int dfs(int pos, vector<int>& P, int count){
    if(pos == 0){
        return count;
    }
    int next = P[pos];
    return dfs(next, P, count + 1);
}

int main(){
    int N;
    cin >> N;
    vector<int> P(N, 0);
    REP(i, N-1){
        cin >> P[i+1];
        P[i+1] -= 1;
    }

    int count = dfs(N-1, P, 0);
    out(count);

    return 0;
}