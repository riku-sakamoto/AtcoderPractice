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



vector<pair<int, int>> getDivisorNumbers(int N){
    vector<pair<int, int>> primes;

    for(LL p=1; p*p <= N; ++p){
        if(N % p == 0){
            if(p != N/p){
                primes.push_back({p, N/p});
                primes.push_back({N/p, p});
            }else{
                primes.push_back({p, N/p});
            }
        }
    }
    
    return primes;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)cin >> A[i];

    map<int, int> counter;
    REP(i, N){
        if(counter.find(A[i]) != counter.end()){
            counter[A[i]] += 1;
        }else{
            counter[A[i]] = 1;
        }
    }

    sort(ALL(A));

    LL ans = 0;
    REPREV(i, N){
        vector<pair<int, int>>divisors = getDivisorNumbers(A[i]);

        for(auto p: divisors){
            if(counter.find(p.first) == counter.end()){
                continue;
            }
            if(counter.find(p.second) == counter.end()){
                continue;
            }
            int num1 = counter[p.first];
            int num2 = counter[p.second];
            ans += 1LL * num1 * num2;
        }
    }

    out(ans);
    return 0;
}