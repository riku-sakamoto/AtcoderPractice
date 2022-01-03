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
    cin >> N;
    vector<LL> A(N, 0);
    vector<LL> B(N, 0);

    REP(i, N){
        cin >> A[i];
    }
    REP(i, N){
        cin >> B[i];
    }

    LL ans = 0;

    sort(ALL(A));
    sort(ALL(B));

    REP(i,N){
        LL b = B[i];
        LL a = A[i];
        ans += abs(b - a);

    }

    cout << ans << endl;
    return 0;


    
}