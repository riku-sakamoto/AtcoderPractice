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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    
}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


auto comp = [](LL l, LL r){return abs(l)<abs(r);};
priority_queue<LL, vector<LL>, decltype(comp)> que(comp);

LL MAX_N = 5*100000;
LL p = 1E9 + 7;
vector<LL> factorials(MAX_N+1,0);
vector<LL> ifactorials(MAX_N+1,0);


LL getPow(LL val, LL n){
    // バイナリ法
    LL ans = 1;
    while(n > 0){
        ans = ans % p;
        if((n & 1) == 1){
            ans = (ans * (val%p)) % p;
        }
        val = ((val%p) * (val%p))%p;
        n = n >> 1;
    }
    return ans%p;
}

LL combination(LL n, LL k){
    if(k==0){return 1;}
    LL val1 = factorials[n];
    LL val2 = ifactorials[k]; //getPow(factorials[k], p-2);
    LL val3 = ifactorials[n-k]; //getPow(factorials[n-k], p-2);
    
    return ((val1 * val2)%p * val3)%p;
}

LL permutation(LL n, LL k){
    if(k==0){return 1;}
    LL val1 = factorials[n];
    // LL val2 = getPow(factorials(k), p-2);
    LL val3 = ifactorials[n-k]; //getPow(factorials[n-k], p-2);

    return ((val1 * val3)%p);
}

LL gcd(LL a, LL b){
    LL min_p = min({a, b});
    LL max_p = max({a, b});

    if(min_p == 0){
        return max_p;
    }

    return gcd(min_p, max_p%min_p);
}

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