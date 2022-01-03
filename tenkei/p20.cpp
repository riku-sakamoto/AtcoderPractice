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

LL LL_pow(int target, int a){
    LL ans = 1;
    FOR(i, 0, a){
        ans *= target;
    }
    return ans;
}

int main(){
    LL a;
    int b, c;
    cin >> a >> b >> c;

    LL d = LL_pow(c, b);

    if(a < d){
        cout << "Yes" << endl;
    }else{
        cout << "No"  << endl;
    }

    return 0;
}