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
    int H, W;
    cin >> H >> W;

    // vector<vector<int>> led = vector<vector<int>>(H, vector<int>(W, 0));
    // REP(i, H){
    //     REP(j, W){
    //         led[i][j]
    //     }
    // }
    
    if(H == 1 || W == 1){
        cout << H * W << endl;
        return 0;
    }
    int ans = (H / 2 + H % 2) * (W / 2 + W % 2);
    cout << ans << endl;
    return 0; 
}