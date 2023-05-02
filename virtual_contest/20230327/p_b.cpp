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
    int T, A;
    cin >> N >> T >> A;

    vector<LL> H(N);
    REP(i, N){
        cin >> H[i];
    }

    int ans = -1;
    double diff_T = 100000000;

    REP(i, N){
        double avgT = T - H[i] * 0.006;

        double tmp_diff_T = abs(avgT - A);
        if (tmp_diff_T < diff_T) {
            // cout << i << "," << avgT << endl;
            ans = i + 1;
            diff_T = tmp_diff_T;
        }
    }

    cout << ans << endl;


    return 0;
}