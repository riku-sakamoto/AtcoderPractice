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

// LL pow2(LL n){ 
//     LL ans = 1;
//     REP(i, n){
//         ans *= 2;
//     }
//     return ans;
// }


int main(){
    LL N, L, R;
    cin >> N >> L >> R;

    LL ans = 0LL;
    for(int i=63; i>=0; --i){
        if((N & (1LL << i)) != 0){
            // ibit == 1
            LL left = (1LL << i);
            LL right = (1LL << (i+1)) - 1;

            if(right < L){
                continue;
            }
            if(left > R){
                continue;
            }

            // cout << i << "," << left << endl;
            // cout << (N & (1 << i)) << endl;
            // cout << (1 << i) << endl;
            chmax(left, L);
            chmin(right, R);
            // cout << left << ", " << right << endl;
            ans += (right - left + 1);
        }
    }
    cout << ans << endl;
    return 0;
}