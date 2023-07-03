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


LL gcd(LL a, LL b){
    LL min_p = min({a, b});
    LL max_p = max({a, b});

    if(min_p == 0){
        return max_p;
    }

    return gcd(min_p, max_p%min_p);
}


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



int main(){
    int N; cin >> N;
    vector<LL> A(N); 
    REP(i, N){cin >> A[i];}
    sort(ALL(A));

    vector<LL> diffA;
    FOR(i, 1, N){
        auto v = A[i] - A[0];
        if(v <= 0){continue;}
        diffA.push_back(v);
    }
    if(diffA.size() == 0){
        out(1); return 0;
    }
    LL gcd_v = diffA[0];
    REP(i, N){
        gcd_v = gcd(diffA[i], gcd_v);
    }
    // cout << "gcd: " << gcd_v << endl;

    if(gcd_v != 1LL){
        out(1);
        return 0;
    }

    set<LL> vals;
    REP(i, N){
        if(A[i] % 2LL == 0LL){
            vals.insert(0);
        }else{
            vals.insert(1);
        }
    }
    out(vals.size());
    return 0;
}