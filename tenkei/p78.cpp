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
    int N, M;
    cin >> N >> M;

    vector<int> nums(N+1, 0);
    int a, b;
    REP(i, M){
        cin >> a >> b;
        if(a < b){
            nums[b] += 1;
        }else if(a > b){
            nums[a] += 1;
        }
    }

    int ans = 0;
    REP(i, N+1){
        if(nums[i] == 1)ans++;
    }

    cout << ans << endl;
    return 0;

    
}