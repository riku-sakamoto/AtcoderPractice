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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){

    LL K;
    int N;
    cin >> K >> N;

    vector<LL> A(N);
    REP(i, N){
        cin >> A[i];
    }

    vector<LL> lengths(N);
    REP(i, N-1){
        lengths[i] = A[i+1] - A[i];
    }

    lengths[N-1] = K - A[N-1] + A[0];

    sort(ALL(lengths));
    LL ans = K - lengths[N-1];
    out(ans);
    return 0;
}