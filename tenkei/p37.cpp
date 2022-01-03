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

/* RMQ: [0, n-1]について区間ごとの最大値を管理する
  update(i, x): i番目の要素をｘに更新（logN）
  query(a, b): [a, b)の最大を取得（logN）
  参照：https://algo-logic.info/segment-tree/
*/
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

    vector<tuple<int, int, LL>> materials;
    REP(i, N){
        int l, r;
        LL v;
        cin >> l >> r >> v;        
        materials.push_back({l, r, v});
    }

    vector<vector<LL>> dp(2, vector<LL>(W+1, -1));
    vector<RMQ<LL>> dpRmq(2, RMQ<LL>(W+1));

    dp[0][0] = 0;
    dpRmq[0].update(0, 0);

    FOR(i, 1, N+1){
        tuple<int, int, LL> mat = materials[i-1];
        int l = get<0>(mat);
        int r = get<1>(mat);
        LL v = get<2>(mat);

        int k = i % 2;
        int pre_k = (i - 1) % 2;
        // cout << k << " " << pre_k << endl;

        // 初期化
        dp[k] = vector<LL>(W+1, -1);
        dpRmq[k].init();

        REP(j, W+1){
            // i個目を選択しない場合
            chmax(dp[k][j], dp[pre_k][j]);

            // i個目を選択する場合
            int cl = max({0, j-r});
            int cr = min({W+1, j-l+1});
            if(cl == cr) continue;

            LL rangeMax = dpRmq[pre_k].query(cl, cr);
            if(rangeMax != -1){
                chmax(dp[k][j], v + rangeMax);
            }

            // RMQの更新
            dpRmq[k].update(j, dp[k][j]);
        }

    }

    int a = N % 2;
    if(dp[a][W] == 0 || dp[a][W] == -1){
        cout << -1 << endl;
    }else{
        cout << dp[a][W] << endl;
    }

    return 0;
    
}