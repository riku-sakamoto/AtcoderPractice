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
    int A, B, C;
    cin >> A >> B >> C;

    int k_min = A / C;
    int k_max = B / C;

    FOR(k , k_min, k_max+1){
        int val = k * C;
        if(val >= A && val <= B){
            cout << val << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}