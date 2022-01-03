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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

LL p = 1E9 + 7;


LL getPow(LL val, LL n){
    // バイナリ法
    LL ans = 1;
    while(n > 0){
        ans = ans % p;
        if((n & 1) == 1){
            ans = (ans * (val%p)) % p;
        }
        val = ((val%p) * (val%p))%p;
        n = n >> 1;
    }
    return ans%p;
}

int main(){
    LL N;
    LL K;
    cin >> N >> K;


    LL ans = 1;
    if(N <= 3){
        REP(i, N){
            ans = (ans * (K - i)) % p;
        }
        cout << ans << endl;
        return 0;
    }

    ans = (ans * K) % p;
    ans = (ans * (K - 1)) % p;
    ans = (ans * (K - 2)) % p;

    if(ans == 0){
        cout << ans << endl;
        return 0;
    }

    LL tmp = getPow(K-2, N-3);

    ans = (ans * tmp) % p;

    cout << ans << endl;

    return 0;
    
}