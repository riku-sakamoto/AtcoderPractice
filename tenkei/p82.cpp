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
typedef unsigned long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPREV(i,n) for(int i=(n-1);i>=(0);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

LL PVALUE = 1000000000+7;

LL getPow(LL val, LL n){
    // バイナリ法
    LL ans = 1;
    while(n > 0){
        ans = ans % PVALUE;
        if((n & 1) == 1){
            ans = (ans * (val%PVALUE)) % PVALUE;
        }
        val = ((val%PVALUE) * (val%PVALUE))%PVALUE;
        n = n >> 1;
    }
    return ans%PVALUE;
}


LL getPowNum(int num){
    LL val = 1;
    REP(i, num){
        val *= 10;
    }
    return val;
}

queue<pair<LL, LL>> getPowMembers(LL L, LL R){
    string L_str, R_str;
    queue<pair<LL, LL>> pow_pair;
    L_str = to_string(L);
    R_str = to_string(R);

    int n_L = L_str.size();
    int n_R = R_str.size();
    LL val_sum = 0;
    LL val_num = 0;

    FOR(n, n_L, n_R + 1){
        LL val_1 = getPowNum(n-1);
        if(n == n_L){
            val_1 = L;
        }
        LL val_2 = getPowNum(n);
        if(n == n_R){
            val_2 = R;
        }
        // cout << val_1 << ", " << val_2 << endl;

        if((val_2 - val_1) % 2 == 0){
            val_num = (val_2 - val_1) / 2;
            val_sum = (val_1 + val_2 - 1);
        }else{
            val_num = (val_2 - val_1);
            val_sum = (val_1 + val_2 - 1) / 2;
        }
        LL _n_num = ((val_sum % PVALUE) * (val_num % PVALUE)) % PVALUE;
        
        pow_pair.push({n, _n_num});
    }

    pow_pair.push({n_R, R % PVALUE});
    return pow_pair;
}


int main(){
    LL L, R;
    cin >> L >> R;

    queue<pair<LL, LL>> pow_pair = getPowMembers(L, R);

    LL ans = 0;
    while(!pow_pair.empty()){
        pair<LL, LL> p = pow_pair.front(); pow_pair.pop();
        // cout << p.first << ", " << p.second << endl;
        ans = (ans + (p.first * p.second) % PVALUE) % PVALUE;
    }

    cout << ans << endl;

    return 0;
}