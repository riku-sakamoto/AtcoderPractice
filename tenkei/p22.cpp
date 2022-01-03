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

LL gcd(LL a, LL b){
    if( a == 0 ){return b;}

    LL c = gcd(b%a, a);
    return c;
}

int main(){
    vector<LL> nums(3);
    REP(i,3)cin>>nums[i];

    sort(ALL(nums));    

    LL k = gcd(nums[0], nums[1]);
    k = gcd(k, nums[2]);

    LL ans = nums[0]/k + nums[1]/k + nums[2]/k - 3;

    cout << ans << endl;
    return 0;
    
}