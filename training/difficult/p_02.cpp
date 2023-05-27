#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
#include <atcoder/modint>
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
using namespace atcoder;
using mint = modint1000000007;


int main(){
    int N;
    LL K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N){
        cin >> A[i];
    }
    
    vector<mint> values(N, mint(0LL));
    REP(i, N){
        auto tmp = A[i];
        REP(j, i){
            if(A[j] > tmp){
                values[i] += 1;
            }
        }
    }

    vector<mint> values_2(N, mint(0LL));
    REP(i, N){
        auto tmp = A[i];
        FOR(j, i + 1, N){
            if(A[j] > tmp){
                values_2[i] += 1;
            }
        }
    }

    mint ans = mint(0LL);
    REP(i, N){
        // cout << values[i].val() << ", " << values_2[i].val() << endl;
        mint tmp = mint(K) * values[i] + mint((K - 1LL) * K / 2LL) * (values[i] + values_2[i]);
        ans += tmp;
    }
    cout << ans.val() << endl;
    return 0;
}