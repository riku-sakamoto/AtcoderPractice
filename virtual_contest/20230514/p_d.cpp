#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
#include <atcoder/modint>
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
    REP(i, vec.size()){cout << vec[i].val() << " ";}
    cout << endl;
}
const LL INF = 1LL << 60;
struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
using namespace atcoder;
using mint = modint1000000007;

int X, Y;
pair<bool, pair<int, int>> check(){
    REP(i, X){
        auto x = X - i;
        auto y = Y + i;
        if(x < 0 || y < 0){
            return {false, {-1, -1}};
        }
        if(y == 2 * x){
            return {true, {x, i}};
        }
    }
    return {false, {-1, -1}};
}


class PermutationMath {
    private:
        int _N;
        LL _M;
    // k ^ -1 = k ^ (M - 2) (mod M)
    public:
        vector<mint> factorials;
        // k! ^ (M - 2)
        vector<mint> ifactorials;
        PermutationMath(int _N, LL _M);
        mint combination(LL N, LL k);
        mint permutation(LL N, LL k);
};

PermutationMath::PermutationMath(int _N, LL _M){
    _N = _N;
    _M = _M;
    factorials = vector<mint>(_N);
    ifactorials = vector<mint>(_N);
    REP(i, _N){
        if (i == 0){
            factorials[i] = mint(1);
            ifactorials[i] = mint(1);
            continue;
        }
        factorials[i] = mint(i) * factorials[i - 1];
        ifactorials[i] = factorials[i].pow(_M - 2LL);
    }
}
mint PermutationMath::combination(LL n, LL k){
    if(k==0){return 1;}
    auto val1 = factorials[n];
    auto val2 = ifactorials[k];
    auto val3 = ifactorials[n-k];
    return val1 * val2 * val3;
}
mint PermutationMath::permutation(LL n, LL k){
    if(k==0){return 1;}
    mint val1 = factorials[n];
    mint val3 = ifactorials[n-k];
    return val1 * val3;

}


int main(){
    cin >> X >> Y;
    
    auto v = check();
    if(!v.first){
        out(0);
        return 0;
    }

    LL p = 1000000007LL;
    PermutationMath pMath(X, p);

    vector<vector<mint>> dp(X + 1);
    dp[0].push_back(mint(1));
    auto row = v.second.first;
    auto col = v.second.second;
    auto ans = pMath.combination(row, col);
    out(ans.val());
    return 0;
}