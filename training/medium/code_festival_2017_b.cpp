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
    int N, M, K;
    cin >> N >> M >> K;

    REP(n1, N + 1){
        int r = K - n1 * M;
        if(r == 0){
            yes();
            return 0;
        }
        if(r * (N - 2 * n1) > 0){
            if(abs(r) % abs(N - 2 * n1) == 0){
                int n2 = abs(r) / abs(N - 2 * n1);
                if(n2 <= M){
                    // cout << "1: " << n1 << endl;
                    yes();
                    return 0;
                }
            }
        }
    }

    REP(n1, M + 1){
        int r = K - n1 * N;
        if(r == 0){
            yes();
            return 0;
        }
        if(r * (M - 2 * n1) > 0){
            if(abs(r) % abs(M - 2 * n1) == 0){
                int n2 = abs(r) / abs(M - 2 * n1);
                if(n2 <= N){
                    yes();
                    return 0;
                }
                // cout << "2: " << n1 << endl;
            }
        }
    }
    no();
    return 0;
}