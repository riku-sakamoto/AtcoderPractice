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


// Sieve of Erastosthenes
vector<LL> getPrimeNumbers(LL N){
    LL count = 0;
    while(count * count < N){
        count += 1;
    }

    vector<bool> num_to_isPrime(count+1, false);
    num_to_isPrime[0] = false;
    num_to_isPrime[1] = false;

    vector<LL> primes;
    FOR(j, 2, count+1){
        if(num_to_isPrime[j] == false){
            primes.push_back(j);
            LL n = 1;
            while(j*n <= count){
                num_to_isPrime[j*n] = true;
                ++n;
            }
        }else{
            continue;
        }
    }

    return primes;
}


int main(){
    LL N;
    cin >> N;

    LL n = 1;
    set<pair<LL, LL>> primes_pairs;
    while(n * n <= N * N){
        vector<LL> primes = getPrimeNumbers(n);

        vector<LL> elems;
        for(LL v: primes){
            if(n % v == 0){
                elems.push_back(v);
            }
        }
        for(LL v: elems){
            if (v <= N && (n * n)/ v <= N){
                // cout << n << ", " << v << ", " << (n * n)/ v << endl;
                primes_pairs.insert({v, (n * n)/ v});
                primes_pairs.insert({(n * n)/ v, v});
            }
            if ((n * n) % (v * v) <= N && v * v <= N && (n * n)/ (v * v) <= N){
                // cout << n << ", " << v << ", " << (n * n)/ v << endl;
                primes_pairs.insert({v * v, (n * n)/ (v * v)});
                primes_pairs.insert({(n * n)/ (v * v), v * v});
            }
        }

        n += 1;
    }
    LL count = primes_pairs.size();
    cout << count << endl; 
    return 0;
}