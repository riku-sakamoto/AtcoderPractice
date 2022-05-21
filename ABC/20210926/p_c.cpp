#define _GLIBCXX_DEBUG
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
    vector<int> A(N);
    LL sumA = 0;
    REP(i, N){
        cin >> A[i];
        sumA += A[i];
    }
    LL X;
    cin >> X;


    LL numMin = X / sumA;
    LL numR = 0;
    LL r = X % sumA;
    REP(i, N){
        if(r < 0){break;}

        r -= A[i];
        numR += 1;
    }

    LL ans = numMin * N + numR;
    cout << ans << endl;
    return 0;
}