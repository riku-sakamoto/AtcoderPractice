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
    LL K;
    cin >> N >> K;
    vector<pair<LL, int>> a(N);
    REP(i, N){
        LL _a;
        cin >> _a;
        a[i] = {_a, i};
    }

    vector<LL> snacks(N, 0);

    LL n1 = K / N;
    LL n2 = K % N;

    REP(i, N){
        snacks[i] += n1;
    }

    sort(ALL(a));

    REP(i, n2){
        pair<LL, int> mem_a = a[i];
        snacks[mem_a.second] += 1;
    }
    
    REP(i, N){
        cout << snacks[i] << endl;
    }

    return 0;
}

