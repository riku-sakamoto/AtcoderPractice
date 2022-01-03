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
    int S;
    LL T;
    cin >> S >> T;

    LL ans = 0;
    REP(i,S+1){
        REP(j, S+1){
            REP(k,S+1){
                if(i + j + k <= S && i*j*k <= T){
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
    
}