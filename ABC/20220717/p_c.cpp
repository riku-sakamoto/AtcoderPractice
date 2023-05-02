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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    

    vector<LL> reds(N+1, 0);
    vector<LL> blues(N+1, 0);
    reds[N] = 1;
    REPREV(i, N+1){
        if (i == 1){
            break;
        }
        blues[i] += reds[i] * X;
        reds[i-1] += reds[i] + blues[i];
        blues[i-1] += blues[i] * Y;
        // cout << reds[i] << ", " << blues[i] << endl;
    }

    out(blues[1]);

    return 0;
}