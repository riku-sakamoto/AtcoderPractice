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
    int N;
    cin >> N;
    vector<int> p(N);
    REP(i, N){
        cin >> p[i];
    }

    REP(i, )

    if(p[0] == 1){
        int n1 = 1;
        REP(i, N){
            if(p[i] == N){
                break;
            }
            n1 += 1;
        }
        if(n1 == N){
            n1 = 0;
        }
        out(n1);
        return 0;
    }

    if(p[N - 1] == 1){

    }

    int n1 = 0;
    REP(i, N){
        if(p[i] == 1){
            break;
        }
        n1 += 1;
    }

    // decend
    int n2 = 1;
    REPREV(i, N){
        if(p[i] == 1){
            n2 += 2;
            break;
        }
        n2 += 1;
    }

    auto ans = min({n1, n2});
    out(ans);
    return 0;
}