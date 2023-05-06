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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    REP(i, N){
        cin >> L[i];
    }
    sort(ALL(L));

    LL ans = 0LL;
    set<tuple<int, int, int>> triangles;
    REP(i, N-1){
        FOR(j, i+1, N){
            int diff = abs(L[i] - L[j]);
            int sum = L[i] + L[j];

            int idx_min = upper_bound(ALL(L), diff) - L.begin();
            int idx_max = lower_bound(ALL(L), sum) - L.begin();

            if(idx_min == N){
                continue;
            }
            if(idx_max == 0){
                continue;
            }
            
            if(idx_max <= j){
                continue;
            }
            
            // idx_min to idx_max - 1
            // j + 1 to idx_max - 1
            int count = idx_max - j - 1;
            count = max({count, 0});
            // cout << i << ", " << j << ", " << idx_min << ", "<< idx_max << endl;
            // cout << "count: " << count << endl;
            ans += (LL)count;
        }
    }

    cout << ans << endl;
    return 0;
}