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


LL P = 998244353LL;

LL RangeSum(LL start, LL end){
    LL add = (start + end) % P;
    LL count = (end - start + 1LL) %P;
    if (add % 2 == 0){
        return ((add / 2LL) * count) % P;
    }

    if(count % 2 == 0){
        return (add * (count / 2LL)) % P;
    }
    // return ((((start % P + end % P) / 2LL) % P) * ((end - start + 1LL) % P)) % P;
}


LL digits(LL value){
    LL digit = 0LL;
    LL value10 = 1LL;
    REP(i, 100){
        if(value < value10){
            break;
        }
        digit += 1LL;
        value10 *= 10LL;
    }

    return value10 / 10LL;
}



int main(){
    LL N;
    cin >> N;

    if(N < 10){
        LL tmp_ans = RangeSum(1LL, N);
        cout << tmp_ans << endl;
        return 0;
    }

    LL value10 = digits(N);
    LL tmp = RangeSum(1LL, N - value10 + 1LL);
    LL ans = tmp % P;

    while(value10 != 10LL){
        LL last = value10 - 1LL;
        LL next = value10 / 10LL;
        LL tmp_sum = RangeSum(1LL, last - next + 1LL);
        ans = (ans + tmp_sum % P) % P;
        value10 /= 10LL;
    }
    tmp = RangeSum(1LL, 9LL);
    ans = (ans + tmp) % P;

    cout << ans << endl;
    return 0;

}