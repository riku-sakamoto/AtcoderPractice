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
#define REP(i,n) for(LL i=0LL;i<(n);++i)
#define REPREV(i,n) for(LL i=(n-1LL);i>=(0LL);--i)
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}
template<typename T> int larger_equal(vector<T>& vec, T val){
    auto ptr = lower_bound(ALL(vec), val);
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> int larger_than(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> int lower_equal(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    int idx = ptr - vec.begin() - 1;
    return idx;
}
template<typename T> int lower_than(vector<T>& vec, T val){
    auto ptr = lower_bound(ALL(vec), val);
    int idx = ptr - vec.begin() - 1;
    return idx;
}
template<typename T> inline void out_vector(vector<T>& vec){
    REP(i, vec.size()){cout << vec[i] << " ";}
    cout << endl;
}
template <typename T> struct Matrix {
    vector<vector<T>> _array;
    int _Nr;
    int _Nc;
    Matrix(int Nr, int Nc): _Nr(Nr), _Nc(Nc) {
        _array = vector(Nr, vector<T>(Nc));
    };

    void to_eye(){
        REP(i, _Nr){
            REP(j, _Nc){
                if(i == j){
                    _array[i][j] = T(1);
                }else{
                    _array[i][j] = T(0);
                }
            }
        }
    }

    vector<T>& operator[] (int i){
        return _array[i];
    }

    Matrix operator* (Matrix& other){
        if(_Nc != other._Nr){
            throw runtime_error("Cannot multiply two matrix");
        }

        Matrix<T> res(_Nr, other._Nc);
        REP(i, _Nr){
            REP(j, other._Nc){
                T val = T(0);
                REP(k, _Nc){
                    val += _array[i][k] * other._array[k][j];
                }
                res[i][j] = val;
            }
        }
        return res;
    }

    void show(){
        REP(i, _Nr){
            REP(j, _Nc){
                cout << _array[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template <typename T> T calcPow(T& val, LL n, T& init_val){
    T ans = init_val;
    while(n > 0){
        if((n & 1) == 1){
            ans = val * ans;
        }
        val = val * val;
        n = (n >> 1);
    }
    return ans;
};
struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};
string str_slice(int i, int j, string& S){
    int n = j - i;
    return S.substr(i, n);
}
using Graph = vector<vector<Edge>>;
const LL INF = 1LL << 60;
const int inf = INT_MAX / 2;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;


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


mint solve(LL N, LL K, LL k, PermutationMath& perm){
    if(N - K < k - 1LL){return mint(0LL);}
    auto c1 = perm.combination(N - K + 1, k);
    if(K == 1LL && k == 1LL){
        return c1;
    }
    auto c2 = perm.combination(K - 1LL, k - 1LL);
    return c1 * c2;
}


int main(){
    LL N, K; cin >> N >> K;

    PermutationMath perm(N, 1000000007LL);
    vector<mint> answers;
    FOR(k, 1LL, K + 1){
        auto v = solve(N, K, k, perm);
        answers.push_back(v);
    }

    for(auto v: answers){
        out(v.val());
    }
    return 0;
}