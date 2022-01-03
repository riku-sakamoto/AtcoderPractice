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
    int K = 46;
    cin >> N;
    vector<LL> A(N);
    vector<LL> B(N);
    vector<LL> C(N);

    vector<LL> RA(K, 0);
    vector<LL> RB(K, 0);
    vector<LL> RC(K, 0);

    REP(i, N){
        cin >> A[i]; 
        RA[A[i] % K] += 1;
    }   
    REP(i, N){
        cin >> B[i]; 
        RB[B[i] % K] += 1;
    }   
    REP(i, N){
        cin >> C[i]; 
        RC[C[i] % K] += 1;
    }   

    
    LL ans = 0;
    REP(i, K){
        REP(j, K){
            REP(k, K){
                if((i + j + k) % K == 0){
                    ans += RA[i] * RB[j] * RC[k];
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}