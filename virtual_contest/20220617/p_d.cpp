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


vector<LL> getPrimeNumbers(LL N){
    vector<bool> isPrime(N+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(LL p=2; p*p <= N; ++p){
        if(isPrime[p] == true){
            for(LL j=2; p*j <= N; ++j){
                isPrime[p*j] = false;
            }
        }
    }


    vector<LL> primes;
    REP(i, N+1){
        if(isPrime[i] == true){
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main(){
    LL Q;
    cin >> Q;

    LL N = 101010;
    vector<LL> primes = getPrimeNumbers(N);

    // REP(i, primes.size()){
    //     cout << primes[i] << endl;
    // }
    
    vector<LL> targets;
    for(auto num: primes){
        if(num == 2){
            continue;
        }

        int idx = lower_bound(ALL(primes), (num + 1) / 2) - primes.begin();
        if(primes[idx] == (num + 1) / 2){
            targets.push_back(num);
        }
    }

    queue<int> que;
    REP(i, Q){
        LL l, r;
        cin >> l >> r;

        int idx_l = lower_bound(ALL(targets), l)- targets.begin();
        int idx_r = lower_bound(ALL(targets), r+1) - targets.begin();
        
        que.push(idx_r - idx_l);


    }

    while(!que.empty()){
        int val = que.front(); que.pop();
        cout << val << endl;
    }

    return 0;
}