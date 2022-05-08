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
    LL P;
    cin >> P;
    vector<LL> A(N);
    REP(i, N)cin>>A[i];

    int n = N/2;
    vector<vector<LL>> nums_to_price(n+1);
    for(int i=0; i<(1<<n); ++i){
        int num = 0;
        LL cost = 0;
        for(int j=0; j<n; ++j){
            // Bit 演算＝＝１だとうまくいかない
            if((i & (1 << j))){
                num += 1;
                cost += A[j];
            }
        }
        nums_to_price[num].push_back(cost);
        // cout << num << ", " << cost << endl; 
    }

    int n2 = N - n;
    vector<vector<LL>> nums_to_price_2(n2+1);
    for(int i=0; i<(1<<n2); ++i){
        int num = 0;
        LL cost = 0;
        for(int j=0; j<n2; ++j){
            // Bit 演算＝＝１だとうまくいかない
            if((i & (1 << j))){
                num += 1;
                cost += A[j+n];
            }
        }
        nums_to_price_2[num].push_back(cost);
        // cout << num << ", " << cost << endl; 
    }

    REP(i, nums_to_price.size()){
        sort(ALL(nums_to_price[i]));
    }

    REP(i, nums_to_price_2.size()){
        sort(ALL(nums_to_price_2[i]));
    }

    LL ans = 0;

    REP(i, n+1){
        int left_K = K - i;
        if(left_K < 0)continue;

        REP(j, nums_to_price[i].size()){
            LL left_P = P - nums_to_price[i][j];
            if(left_P < 0)continue;
            if(left_K >= nums_to_price_2.size())continue;

            int num = lower_bound(ALL(nums_to_price_2[left_K]), left_P+1) - nums_to_price_2[left_K].begin();
            ans += (LL)num;
        }
    }

    cout << ans << endl;

    return 0;
}