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

int main(){
    int N, K;
    cin >> N >> K;

    LL count = 0LL;
    FOR(b, K + 1, N + 1){
        int n = N / b;
        int r = N % b;

        LL _count = 0LL;
        _count += 1LL * n * (b - K);

        if(r != 0 && r >= K){
            if (K == 0){
                _count += r;
            }else{
                _count += r - K + 1LL;
            }
        }
        count += _count;
        // cout << b << ", " << _count << endl;
    }

    out(count);
    return 0;
}