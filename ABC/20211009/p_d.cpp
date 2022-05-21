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
    int N;
    cin >> N;
    vector<LL> a(N);
    vector<LL> b(N);
    REP(i,N)cin >> a[i];
    REP(i,N)cin >> b[i];
    LL VAL = 998244353;

    int nAll = 3002;
    vector<LL> ans(nAll, 0);
    vector<LL> sums(nAll, 0);

    FOR(n, a[0], b[0]+1){
        ans[n] = 1;
    }

    LL tmp0 = 0;
    REP(i, nAll){
        tmp0 = (tmp0 + ans[i]) % VAL;
        sums[i] = tmp0;
    }

    FOR(i, 1, N){
        REP(i, nAll){
            ans[i] = 0;
        }

        FOR(n, a[i], b[i]+1){
            ans[n] = sums[n];
        }

        LL tmp = 0;
        REP(i, nAll){
            tmp = (tmp + ans[i]) % VAL;
            sums[i] = tmp;
        }
    }

    cout << sums[nAll-1] << endl;
    return 0;
}