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
    LL K;
    cin >> N >> K;

    vector<int> A(N, 0);
    vector<int> B(N, 0);

    REP(i, N){
        cin >> A[i];
    }
    REP(i, N){
        cin >> B[i];
    }

    LL diff = 0;
    REP(i, N){
        diff += abs(A[i] - B[i]);
    }

    if(diff > K){
        cout << "No" << endl;
        return 0;
    }

    if((diff-K)%2 == 0){ 
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;

}