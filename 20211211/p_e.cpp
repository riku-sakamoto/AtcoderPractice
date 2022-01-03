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

// 6 1052
// 1 5 10 50 100 500

int main(){
    int N;
    LL X;
    cin >> N >> X;

    vector<LL> A(N);
    REP(i, N){
        cin >> A[i];
    }

    vector<LL> ans(N, 0);
    int i = 0;
    while(true){
        // cout << X << endl;
        if ( i == N - 1 ){
            ans[i] = X / A[i];
            break;
        }
        LL target = X % A[i+1];
        LL c = target / A[i];
        LL max_c = A[i+1] / A[i];
        // cout << c << ", " << max_c << endl;

        if(c >= max_c){
            i += 1; 
            continue;
        }

        LL val1 = target / A[i];
        LL val2 = (target + (max_c - c) * A[i]) / A[i+1];
        if(val1 < val2){
            X -= c * A[i];
            ans[i] = c;
        }else{
            X += (max_c - c) * A[i];
            ans[i] = max_c - c;
        }
        
        i += 1;
    }

    // REP(i, N){
    //     cout << A[i] << ":" << ans[i] << endl;
    // }

    LL c_ans = 0;
    REP(i, N){
        c_ans += ans[i];
    }

    cout << c_ans << endl;
    return 0;
    
}