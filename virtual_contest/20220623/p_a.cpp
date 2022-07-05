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
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(N);
    REP(i, M)cin >> A[i];

    int ans1 = 0;
    REP(i, M){
        if(A[i] > X){
            ans1 += 1;
        }
    }

    int ans2 = 0;
    REP(i, M){
        if(A[i] < X){
            ans2 += 1;
        }
    }
    int ans = min({ans1, ans2});

    out(ans);

    return 0;
}