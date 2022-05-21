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
    string S;
    cin >> S;

    string maxS = S;
    string minS = S;

    REP(i, S.size()){
        char c = S[S.size() - 1];
        S.pop_back();

        S = c + S;
        if(maxS < S){
            maxS = S;
        }

        if(minS > S){
            minS = S;
        }

    }

    cout << minS << endl;
    cout << maxS << endl;
    return 0;
}