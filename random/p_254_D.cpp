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


vector<pair<LL, LL>> prime_factorize(LL N) {
    vector<pair<LL, LL> > res;
    for (LL p = 2; p * p <= N; ++p) {
        if (N % p != 0) continue;
        LL ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % p == 0) {
            ++ex;
            N /= p;
        }

        // その結果を push
        res.push_back({p, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


int main(){
    LL N;
    cin >> N;

    vector<LL> squares;
    for(LL i=1; i*i <= N; ++i){
        squares.push_back(i * i);
    }
    int nsqs = squares.size();

    int count = 0;
    for(LL i=1; i<=N; ++i){
        auto primes = prime_factorize(i);
        LL j = 1;
        for(auto p: primes){
            if(p.second % 2 == 1){
                j *= p.first;
            }
        }

        REP(k, nsqs){
            LL newj = j * squares[k];
            if(newj > N){
                // cout << "out: " << j << endl;
                break;
            }

            ++count;
            // cout << i << ", " << j << endl;
        }
    }

    out(count);
    return 0;
}