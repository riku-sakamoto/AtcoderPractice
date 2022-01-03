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

vector<pair<LL, LL>> elastenes(LL N){
    vector<pair<LL, LL>> elems;

    LL i = 2;
    while(i * i <= N){
        if(N % i != 0){
            i+=1;
            continue;
        }

        LL j = 0;
        while(N % i == 0){
            j += 1;
            N /= i;
        }

        elems.push_back({i, j});
        i+=1;
    }
    if ( N != 1){
        elems.push_back({N, 1});
    }

    return elems;

}


int main(){
    LL N;
    cin >> N;

    vector<pair<LL,LL>> elems = elastenes(N);
    
    if(elems.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    LL n = 0;
    for(auto x: elems){
        n += x.second;
    }

    LL ans = 0;
    while(n != 1){
        n = n / 2 + n % 2;
        ans += 1;
    }

    cout << ans << endl;

    return 0;
    
}