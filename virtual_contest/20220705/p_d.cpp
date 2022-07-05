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
    LL M;
    cin >> N >> M;

    REP(x, N+1){
        LL N_ = N - x;
        LL M_ = M - 2 * x;

        LL y = -M_ + 4 * N_;
        LL z = M_ - 3 * N_;
        if(y >= 0 && y <= N && z >= 0 && z <= N){
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}