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
    int N;
    cin >> N;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];


    LL sum_A = 0;
    REP(i, N){
        sum_A += A[i];
    }

    LL min_diff = sum_A;
    LL tmp = 0;
    int idx = 0;
    REP(i, N){
        tmp += A[i];
        if(min_diff > abs(sum_A - 2 * tmp)){
            min_diff = abs(sum_A - 2 * tmp);
            idx = i;
        }
    }

    cout << min_diff << endl;
    return 0;
}