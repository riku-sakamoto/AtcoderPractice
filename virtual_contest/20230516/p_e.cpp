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
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPREV(i,n) for(int i=(n-1);i>=(0);--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}
template<typename T> T larger_equal(vector<T>& vec, T val){
    auto ptr = lower_bound(ALL(vec), val);
    if(ptr == vec.end()){
        return T(-1);
    }
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> T larger_than(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    if(ptr == vec.end()){
        return T(-1);
    }
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> T lower_equal(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    int idx = ptr - vec.begin() - 1;
    return idx;
}
template<typename T> T lower_than(vector<T>& vec, T val){
    auto ptr = lower_bound(ALL(vec), val);
    int idx = ptr - vec.begin() - 1;
    return idx;
}
template<typename T> inline void out_vector(vector<T>& vec){
    REP(i, vec.size()){cout << vec[i] << " ";}
    cout << endl;
}
const LL INF = 1LL << 60;
struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>>data(N);
    REP(i, N){
        cin >> data[i].first;
    }
    REP(i, N){
        cin >> data[i].second;
    }
    sort(ALL(data));
    vector<int> A(N);
    vector<int> B(N);

    REP(i, N){
        tie(A[i], B[i]) = data[i];
    }

    int max_a = 5001;
    vector<vector<mint>> dp(N + 1, vector<mint>(max_a, mint(0)));
    dp[0][0] = mint(1);

    REP(i, N){
        REP(j, max_a){
            dp[i + 1][j] = dp[i][j];
            if(j >= B[i]){
                dp[i + 1][j] += dp[i][j - B[i]];
            }
        }
    }

    mint ans = mint(0);
    REP(i, N){
        auto diff = A[i] - B[i];
        if(diff < 0){
            continue;
        }
        // cout << A[i] << ", " << B[i] << ", " << diff << endl;
        REP(j, diff + 1){
            // i = 個数
            // i = 0 -> 個数は１
            // 個数 - 1したいので，iでよい 
            ans += dp[i][j];
        }
    }
    out(ans.val());
    return 0;
}