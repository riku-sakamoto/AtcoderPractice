#define _GLIBCXX_DEBUG
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

LL pow(int k, int n){
    LL val = 1;
    REP(i, n){
        val *= k;
    }
    return val;
}

int chage_val(string target, int k){
    LL val = 0;
    FOR(i, 0, (int)target.size()){
        char c = target[i];
        int v = c- '0';
        int n = (int)target.size() - 1 - i;
        val += v * pow(k, n);
    }
    return val;
}


int main(){
    int K;
    cin >> K;
    string A, B;
    cin >> A >> B;

    LL a = chage_val(A, K);
    LL b = chage_val(B, K);

    LL ans = a * b;

    cout << ans << endl;
    return 0;
    
}