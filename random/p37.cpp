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


template <typename T>
struct RMQ{
    const T INIT_VALUE = -1;
    int n; // 葉の数
    vector<T> dat; // 完全二分木の配列
    // メンバイニシャライザ
    // 全体の要素数は2n-1。4n_あれば十分。
    RMQ(int n_): n(), dat(n_*4, INIT_VALUE) {
        // 葉の数は 2^x の形
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
    }

    void init(){
        REP(i, (int)dat.size()){
            dat.at(i) = INIT_VALUE;
        }
    }

    void update(int i, T x){
        i += n - 1;
        dat[i] = x;
        while(i > 0){
            // 親へのアクセス
            i = (i - 1)/2;
            dat[i] = max(dat[i*2 + 1], dat[i*2 + 2]);
        }
    }

    T query(int a, int b){ return query_sub(a, b, 0, 0, n);}
    T query_sub(int a, int b, int k, int l, int r){
        // k: 現在のノードの位置
        // [l, r): dat[k]が表している区間
        if(r <= a || b <= l){
            // 範囲外
            return INIT_VALUE;
        }
        else if(a <= l && r <= b){
            // 範囲内
            return dat[k];
        }
        else{
            // 範囲の一部か被る場合
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

int main(){
    int W, N;
    cin >> W >> N;
    vector<tuple<int, int, LL>> LR;
    REP(i,N){
        int L, R;
        LL V;
        cin >> L >> R >> V;
        LR.push_back({L, R, V});
    }

    vector<RMQ<LL>> dp;
    RMQ<LL> init_rmq = RMQ<LL>(W+1);
    init_rmq.update(0, 0);
    dp.push_back(init_rmq);

    REP(i, N){
        int l = get<0>(LR[i]);
        int r = get<1>(LR[i]);
        LL v = get<2>(LR[i]);
        RMQ<LL> rmq = RMQ<LL>(W+1);
        RMQ<LL> pre_rmq = dp[i];

        rmq.update(0, 0);
        REP(j, W+1){
            if(j - l < 0){
                rmq.update(j, pre_rmq.query(j, j+1));
                continue;
            }
            int l_j = max({0, j - r});
            int r_j = max({0, j - l});
            LL val = pre_rmq.query(l_j, r_j + 1);
            LL val2 = pre_rmq.query(j, j+1);
            if(val == -1){
                rmq.update(j, val2);
                continue;
            }
            
            LL updateVal = max({val2, val + v});
            rmq.update(j, updateVal);
        }
        dp.push_back(rmq);
    }

    LL ans = dp[N].query(W, W+1);
    if(ans == 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}