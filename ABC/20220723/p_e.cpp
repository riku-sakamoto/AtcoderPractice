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
    int C;
    cin >> N >> C;
    vector<pair<int, int>> ops(N);

    REP(i, N){
        cin >> ops[i].first >> ops[i].second;
    }

    vector<int> ans(N, 0);
    REP(k, 30){
        vector<int> bit_to_bit = {0, 1};
        int c = BIT(C, k);
        REP(i, N){
            vector<int> tmp_bit_to_bit = {0, 1};
            int t = ops[i].first;
            int c = BIT(ops[i].second, k);
            if(t==1){
                tmp_bit_to_bit[0] = 0&c;
                tmp_bit_to_bit[1] = 1&c;
            }
            if(t == 2){
                tmp_bit_to_bit[0] = 0|c;
                tmp_bit_to_bit[1] = 1|c;
            }
            if(t==3){
                tmp_bit_to_bit[0] = 0^c;
                tmp_bit_to_bit[1] = 1^c;
            }

            // 初期０からbit_to_bit[0]になり，この操作で，tmp_bit_to_bitによる写像
            int zero_to_bit = tmp_bit_to_bit[bit_to_bit[0]];
            int one_to_bit = tmp_bit_to_bit[bit_to_bit[1]];
            bit_to_bit = {zero_to_bit, one_to_bit};
            c = bit_to_bit[c];

            ans[i] |= c << k;
        }
    }

    REP(i, N){
        out(ans[i]);
    }

    return 0;
}