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
#define REPREV(i,n) for(int i=(n-1);i>=(0);--i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int inf = INT_MAX / 2;

//modintの使い方
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
// using mint = modint;
// mint::set_mod(M)
// or: typedef modint mint;

mint val = mint(2).pow(300);

int main(){
    
}

template<typename T> T ceiling(T a, T m){return (a + m - 1) / m;}


struct StringDecorator
{
    string S;
    int N;
    // rights[i][j]: the index where i-th char exists larger than j-th index
    vector<vector<int>> rights;

    // lefts[i][j]: the index where i-th char exists smaller than j-th index
    vector<vector<int>> lefts;

    // before initialization, converting to each char in s to int
    // example: for(auto& c: s){c -= '0'} or {c -= 'a'};
    StringDecorator(string s){
        S = s; N = s.size();
        rights = vector<vector<int>>(26, vector<int>(N));
        lefts = vector<vector<int>>(26, vector<int>(N));
        initialize_position();
    }
    void initialize_position(){
        // num. of alphabets is 26.
        // initialize last index and first index;
        REP(c, 26){rights[c][N - 1] = inf; lefts[c][0] = -1;};
        REPREV(i, N - 1){
            REP(c, 26){rights[c][i] = rights[c][i + 1];}
            rights[S[i + 1]][i] = i + 1;
        }
        FOR(i, 1, N){
            REP(c, 26){lefts[c][i] = lefts[c][i - 1];}
            lefts[S[i - 1]][i] = i - 1;
        }
    }   

    // search index of c larger than idx
    int search_right(int c, int idx){
        if(idx == inf){return inf;}
        if(idx < 0){
            if(S[0] == c){return 0;}
            idx = 0;
        }
        return rights[c][idx];
    }

    int search_left(int c, int idx){
        if(idx == -1){return -1;}
        if(idx == N){
            if(S[N - 1] == c){return N - 1;}
            idx = N - 1;
        }
        return lefts[c][idx];
    }

};


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


// ランレングス圧縮
vector<pair<char, int>> rle_compress(string s){
    vector<pair<char, int>> vec;
    int count = 0;
    char pre;
    for(int i = 0; i < (int)s.size(); ++i){
        if(i == 0){
            pre = s[i];
            count += 1;
            continue;
        }

        if(pre == s[i]){
            ++count;
        }else{
            vec.push_back({pre, count});
            pre = s[i];
            count = 1;
        }
    }
    vec.push_back({pre, count});
    return vec;
}

// string -> number
string S = "123";
int num = stoi(S);

// 引数 l が優先度の低い要素であるときに true を返却
auto comp = [](LL l, LL r){return abs(l)<abs(r);};
priority_queue<LL, vector<LL>, decltype(comp)> que(comp);

LL MAX_N = 5*100000;
LL p = 1E9 + 7;
vector<LL> factorials(MAX_N+1,0);
vector<LL> ifactorials(MAX_N+1,0);

bool exhausticSearch(int n){
    // ｎまでの全探索
    REP(i, 1<<n){
        REP(j, n){
            // ==1にしない．i & (1 << j) は１が帰ってくるとは限らない．（ビット演算）
            if((i & (1 << j)) != 0){
                // jビット目が１でないとき
            }

            // もし対象iがLLのときは１LLにするのを忘れない！！
            if((i & (1LL << j)) != 0){
                // jビット目が１でないとき
            }
        }
    }
    return true;
}


// Sieve of Erastosthenes
// N以下の素数をすべて列挙する
// N log log N
// 約数ならもっと高速化できる
vector<LL> getPrimeNumbers(LL N){
    vector<bool> isPrime(N+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(LL p=2; p*p <= N; ++p){
        if(isPrime[p] == true){
            for(LL j=2; p*j <= N; ++j){
                isPrime[p*j] = false;
            }
        }
    }


    vector<LL> primes;
    REP(i, N+1){
        if(isPrime[i] == true){
            primes.push_back(i);
        }
    }
    
    return primes;
}


// 素因数分解
// O(sqrt N)
vector<pair<LL, LL>> prime_factorize(LL N) {
    vector<pair<LL, LL> > res;
    for (LL p = 2; p * p <= N; ++p) {
        if (N % p != 0) continue;
        LL ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % p == 0) {
            ++ex;
            N /= p;
        }

        // その結果を push
        res.push_back({p, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


// LL getPow(LL val, LL n){
//     // バイナリ法
//     LL ans = 1;
//     while(n > 0){
//         ans = ans % p;
//         if((n & 1) == 1){
//             ans = (ans * (val%p)) % p;
//         }
//         val = ((val%p) * (val%p))%p;
//         n = n >> 1;
//     }
//     return ans%p;
// }

LL extgcd(LL a, LL b, LL x, LL y){
    if(b == 0LL){
        x = 1LL; y = 0LL;
        return a;
    }

    LL d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}


LL gcd(LL a, LL b){
    LL min_p = min({a, b});
    LL max_p = max({a, b});

    if(min_p == 0){
        return max_p;
    }

    return gcd(min_p, max_p%min_p);
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
    factorials = vector<mint>(_N + 1);
    ifactorials = vector<mint>(_N + 1);
    REP(i, _N + 1){
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
    if(k==0LL){return mint(1LL);}
    auto val1 = factorials[n];
    auto val2 = ifactorials[k];
    auto val3 = ifactorials[n-k];
    return val1 * val2 * val3;
}
mint PermutationMath::permutation(LL n, LL k){
    if(k==0LL){return mint(1LL);}
    mint val1 = factorials[n];
    mint val3 = ifactorials[n-k];
    return val1 * val3;

}


/* RMQ: [0, n-1]について区間ごとの最大値を管理する
  update(i, x): i番目の要素をｘに更新（logN）
  query(a, b): [a, b)の最大を取得（logN）
  参照：https://algo-logic.info/segment-tree/
*/
template <typename T>
struct RMaxQ{
    const T INIT_VALUE = -1;
    int n; // 葉の数
    vector<T> dat; // 完全二分木の配列
    // メンバイニシャライザ
    // 全体の要素数は2n-1。4n_あれば十分。
    RMaxQ(int n_): n(), dat(n_*4, INIT_VALUE) {
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


void padding(){
    // 0padding
    int M = 3;
    cout << setfill('0') << right << setw(2) << M << endl;
}

void gridSearch(){
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for(auto dir: dirs){
        
    }
}

void maze_search(){
    // up_down * 2, left_right * 2, 斜め右 * 2, 斜め左 * 2
    vector<int> dirx = {0, 0, 1, -1, 1, -1, 1, -1};
    vector<int> diry = {1, -1, 0, 0, 1, -1, -1, 1};
    int i = 0;
    int j = 0;
    // k = 移動の種類数
    REP(k, 8){
        REP(t, 5){
            auto ni = i + dirx[k] * t;
            // check_in 
        }
        
    }
}


int maze_solve(vector<vector<char>>& maze, int is, int js, int ie, int je){
    int H, W;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    queue<tuple<int, int, int>> pos;
    // 登録済みの記憶
    vector<vector<bool>> seen(H, vector<bool>(W,false));
    pos.push({is, js, 0});
    seen[is][js] = true;
    while (!pos.empty())
    {
        auto v = pos.front(); pos.pop();
        for(auto p: moves){
            int i, j, point;
            tie(i, j, point) = v;
            if(i == ie && j == je){
                return point;
            }

            int i_n = i + p.first;
            int j_n = j + p.second;
            if(i_n >= 0 && i_n < H && j_n >= 0 && j_n < W){
                if(seen[i_n][j_n]){continue;}
                if(maze[i_n][j_n] == '#'){continue;}
                pos.push({i_n, j_n, point + 1});
                // que にいれた時点で登録する
                seen[i_n][j_n] = true;
            }
        }
    }
    return 0;
}

// ダブリング

// 対象が複数の場合
// dp[p][i] : i番目の情報が2^p回移動した先の情報
// dp[p + 1][i] = dp[p][dp[p][i]]
// 2^(p+1) = 2^p * 2^p



// string

// substr(index, count) なことに注意．（countなのでスライスではない）

string str_slice(int i, int j, string& S){
    int n = j - i;
    return S.substr(i, n);
}


// Example 尺取り法

void solve(){
    // semi-open range
    int start = 0;
    int end = 0;
    int N = 10;
    vector<int> A(N);
    LL ans;
    // threshold
    LL K = 0LL;
    LL tmp_sum = 0LL;
    REP(start, N){
        while(end < N && tmp_sum < K){
            tmp_sum += A[end];
            ++end;
        }

        if(tmp_sum < K){
            break;
        }
        ans += (N - end + 1);
        tmp_sum -= A[start];
    }
}

