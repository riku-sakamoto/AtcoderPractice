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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}


LL A, B, X;

LL digits(LL x){
    string s = to_string(x);
    return (LL)(s.size());
}

LL binary_s(LL start, LL end){
    if(end - start <= 1){
        return start;
    }
    LL mid = (start + end) / 2;
    LL cost = A * mid + B * digits(mid);

    if(cost > X){
        end = mid;
        return binary_s(start, end);
    }else{
        start = mid;
        return binary_s(start, end);
    }
}

int main(){
    cin >> A >> B >> X;

    LL max_val = 1000000001LL;
    LL ans = binary_s(0LL, max_val);

    out(ans);
    return 0;
}