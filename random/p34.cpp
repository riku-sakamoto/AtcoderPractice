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
    int N, K;
    cin >> N >> K;

    vector<LL> A(N);
    map<int, int> countMap;
    REP(i, N){
        cin >> A[i];
        countMap[A[i]] = 0;
    }

    int i_l = 0;
    int i_r = 0;
    set<LL> values;
    int ans = 0;
    while(i_r < N){
        values.insert(A[i_r]);
        countMap[A[i_r]] += 1;
        if(values.size() <= K){
            chmax(ans, i_r - i_l + 1);
            ++i_r;
            continue;
        }

        while(values.size() > K){
            countMap[A[i_l]] -= 1;
            if(countMap[A[i_l]] == 0){
                values.erase(A[i_l]);
            }
            ++i_l;
        }
        // cout << values.size() << endl;
        // cout << i_r - i_l + 1 << endl;
        chmax(ans, i_r - i_l + 1);
        ++i_r;
    }

    cout << ans << endl;

    return 0;
}