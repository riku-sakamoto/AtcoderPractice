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
    vector<int> P(N, 0);
    vector<int> q(N, 0);
    REP(i, N){
        int p;
        cin >> p;
        q[p-1] = i + 1;
    }

    // REP(i, N){
    //     int p =i + 1;
    //     int index = lower_bound(ALL(P), p) - P.begin();

    //     q[i] = (index + 1);
        
    // }

    REP(i, N){
        cout << q[i] << " ";
    }

    return 0;

    
}