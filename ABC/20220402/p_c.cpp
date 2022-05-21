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

int main(){
    int N;
    LL K, X;
    cin >> N >> K >> X;
    vector<LL> A(N);
    REP(i, N){
        cin >> A[i];
    }

    sort(ALL(A));
    reverse(ALL(A));

    bool isFinished = false;
    REP(i, N){
        LL ki = A[i] / X;
        LL dec_k = min(ki, K);
        K -= dec_k;
        A[i] = A[i] - dec_k * X;

        if(K == 0){
            isFinished = true;
            break;
        }
    }

    if(isFinished == false){
        sort(ALL(A));
        reverse(ALL(A));
        REP(i, N){
            LL dec_k = 1;
            K -= dec_k;
            A[i] = 0;

            if(K == 0){
                isFinished = true;
                break;
            }
        }
    }
    
    LL ans = 0;
    REP(i, N){
        ans += A[i];
    }

    cout << ans << endl;
    return 0;
}