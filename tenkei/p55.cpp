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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int N;
    LL P, Q;
    cin >> N >> P >> Q;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];

    LL ans = 0;
    REP(i, N){
        FOR(j, i+1, N){
            FOR(k, j+1, N){
                FOR(l, k+1, N){
                    FOR(m, l+1, N){
                        LL tmp = A[i] % P;
                        tmp = (tmp * (A[j] % P)) % P;
                        tmp = (tmp * (A[k] % P)) % P;
                        tmp = (tmp * (A[l] % P)) % P;
                        tmp = (tmp * (A[m] % P)) % P;
                        if (tmp == Q){
                            ans += 1;
                        }
                    }
                }
            }    
        }
    }
    cout << ans << endl;
    return 0;
    
}