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

LL convertTo10d(string N){
    LL ans = 0;
    LL digit = 1;
    for(int i=N.size()-1; i>=0; --i){
        int n = N[i] - '0';
        ans += 1LL * n * digit;
        digit *= 8LL;
    }
    return ans;
}

string convertTo9d(LL N){
    string ans = "";
    if (N == 0){
        return "0";
    }
    while(N != 0){
        LL r = N % 9;
        if(r == 8){
            r = 5;
        }
        char c = '0' + r;
        ans = c + ans;

        N /= 9;
    }
    return ans;
}

int main(){
    string N;
    int K;
    cin >> N >> K;

    REP(i, K){
        LL val = convertTo10d(N);
        // cout << val << endl; 
        N = convertTo9d(val);
    }

    
    cout << N << endl;
    return 0;
}