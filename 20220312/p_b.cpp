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
    cin >> N;  

    vector<LL> A(N, 0);
    vector<LL> B(N, 0);

    REP(i, N){
        cin >> A[i];
    }
    set<LL> setB;

    REP(i, N){
        cin >> B[i];
        setB.insert(B[i]);
    }

    int ans1 = 0;
    REP(i, N){
        if(A[i] == B[i]){
            ans1 += 1;
        }
    }

    int ans2 = 0;

    REP(i, N){
        auto itr = setB.find(A[i]);
        if(itr != setB.end()){
            ans2 += 1;
        }
    }

    ans2 = ans2 - ans1;

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}