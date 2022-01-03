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
    LL N;
    cin >> N;
    vector<LL> ABC(3, 0);
    cin >> ABC[0] >> ABC[1] >> ABC[2];

    sort(ALL(ABC), greater<LL>());

    LL ans = 10000;

    REP(i, 10000){
        
        REP(j, 10000){
            LL r = N - i*ABC[0] - j*ABC[1];

            if(r < 0)continue;

            if(r % ABC[2] == 0){
                LL cnt = i + j + r / ABC[2];
                if(cnt < ans){
                    ans = cnt;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;

}