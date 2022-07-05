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
    LL X, A, D, N;
    cin >> X >> A >> D >> N;

    if (D == 0){
        cout << abs(X - A) << endl;
        return 0;
    }

    LL min_val = (D > 0)? A: A + (N - 1) * D;
    LL max_val = (D > 0)? A + (N - 1) * D: A;

    if (X < min_val){
        cout << abs(min_val - X) << endl;
        return 0;
    }

    if (X > max_val){
        cout << abs(max_val - X) << endl;
        return 0;
    }


    // cout << min_val << ", " << max_val << endl;
    LL D_plus = abs(D);
    LL k = (X - min_val) / D_plus;
    LL tmp_val1 = abs((min_val + k * D_plus) - X);
    LL tmp_val2 = abs(min_val + (k + 1) * D_plus - X);

    // LL true_k = (tmp_val1 > tmp_val2)? k+1: k;
    LL ans = min({tmp_val1, tmp_val2});

    cout << ans << endl;

    return 0;
}