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
    vector<int> a(N);
    REP(i, N)cin >> a[i];

    vector<int> newA;
    int counter = 1;
    REP(i, N){
        if(a[i] == counter){
            newA.push_back(i);
            ++counter;
        }
    }

    if(newA.size() == 0){
        cout << -1 << endl;
    }else{
        int ans = N - newA.size();
        cout << ans << endl;
    }
    return 0;
}
