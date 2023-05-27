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
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPREV(i,n) for(int i=(n-1);i>=(0);--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}
const LL INF = 1LL << 60;
const int inf = INT_MAX / 2;
template<typename T> T ceiling(T a, T m){return (a + m - 1) / m;}

LL N, M;

int main(){
    cin >> N >> M;
    LL ans = INF;

    // 1 < a <= ceil(sqrt(N))
    for(LL a = 1LL; a <= N; ++a){
        auto b = (M + a - 1LL) / a;
        if(b <= N){
            auto val = a * b;
            chmin(ans, val);
        }
        if(a > b){
            break;
        }
    }
    if(ans == INF){
        out(-1);
    }else{
        out(ans);
    }
    return 0;
}
