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
    vector<LL> A(N);
    LL sum = 0LL;
    REP(i, N){
        cin >> A[i];
        sum += A[i];
    }

    LL val = sum / N;
    LL val2 = val + 1LL;

    LL cost = 0LL;
    LL cost2 = 0LL;
    REP(i, N){
        cost += (A[i] - val) * (A[i] - val);
        cost2 += (A[i] - val2) * (A[i] - val2);
    }

    LL min_cost = min({cost, cost2});

    cout << min_cost << endl;
    return 0;
}