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
    int L, R;
    string S;
    cin >> L >>R;
    cin >> S;

    REP(i, S.size()){
        int num = i+1;

        if(num < L || num > R){
            cout << S[i];
        }else{
            cout << S[(R+L-num)-1];
        }

    }
    cout << endl;

    return 0;
}