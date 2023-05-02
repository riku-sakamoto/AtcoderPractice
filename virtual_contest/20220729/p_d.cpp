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

int main(){
    int N;
    cin >> N;
    vector<LL> a(N);
    REP(i, N)cin >> a[i];

    vector<LL> cost(N, 0LL);
    FOR(i, 1, N){
        if (i == 1){
            cost[i] = cost[i-1] + abs(a[i] - a[i-1]);
            continue;
        }
        cost[i] = min({cost[i-1] + abs(a[i] - a[i-1]),\
                        cost[i-2] + abs(a[i] - a[i-2])});
    }

    out(cost[N-1]);

    return 0;
}