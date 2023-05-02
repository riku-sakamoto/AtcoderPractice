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
    REP(i, N){
        cin >> A[i];
    }

    vector<LL> sumA(N, 0);
    vector<LL> sumA2(N, 0);
    REP(i, N){
        if (i == 0){
            sumA[i] = A[i];
        }else{
            sumA[i] = sumA[i - 1] + A[i];
        }

        if (i == 0){
            sumA2[i] = A[i] * A[i];
        }else{
            sumA2[i] = sumA2[i - 1] + A[i] * A[i];
        }
    }

    LL ans = 0LL;
    FOR(n, 1, N){
        LL tmp = n * A[n] * A[n] - 2 * A[n] * sumA[n - 1] + sumA2[n - 1];
        // cout << sumA[n - 1] << endl;
        // cout << sumA2[n - 1] << endl;
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}