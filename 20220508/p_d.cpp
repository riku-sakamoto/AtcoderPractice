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
    LL N;
    cin >> N;

    LL count = 0;
    while(count * count * count < N){
        count += 1;
    }

    vector<bool> candidates(count+1, false);
    vector<LL> sosuu;
    
    FOR(j, 2, count+1){
        if(candidates[j] == false){
            sosuu.push_back(j);
            LL n = 1;
            while(j*n <= count){
                candidates[j*n] = true;
                ++n;
            }
        }else{
            continue;
        }
    }

    if(sosuu.size() <= 1){
        cout << 0 << endl;
        return 0;
    }

    LL ans = 0;
    FOR(i, 1, sosuu.size()){
        LL val = sosuu[i] * sosuu[i] * sosuu[i];
        LL target = N / val;
        LL idx = lower_bound(ALL(sosuu), target+1) - sosuu.begin();
        // cout << target << ", " << val << ", " << idx << endl;
        ans += min(idx, (LL)i);
    }

    cout << ans << endl;
    return 0;
}