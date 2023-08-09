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
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
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
int N, K;

void post(int start, int k){
    vector<int> vals;
    REP(i, K + 1){
        if(i == k){continue;}
        vals.push_back(start + i);
    }

    cout << "? ";
    for(auto v: vals){
        cout << v + 1 << " ";
    }
    cout << endl;
    cout << flush;
}


void post_2(int start){
    vector<int> vals;
    REP(i, K){
        vals.push_back(start - i);
    }

    cout << "? ";
    for(auto v: vals){
        cout << v + 1 << " ";
    }
    cout << endl;
    cout << flush;
}

int main(){
    cin >> N >> K;

    vector<int> vals;
    vector<int> answers(N);

    int n = N / (K + 1);
    int start = 0;
    int tmps = 0;
    
    REP(i, n){
        start = i * (K + 1);
        map<int, int> response;
        tmps = 0;
        REP(k, K + 1){
            post(start, k);
            int val; cin >> val;
            tmps ^= val;
            response[k] = val;
        }

        for(auto p: response){
            auto v = (tmps ^ p.second);
            answers[start + p.first] = v;
        }
    }

    int last_idx = n * (K + 1) - 1;
    tmps = 0;
    REP(i, K - 1){
        tmps ^= answers[last_idx - i];
    }
    FOR(i, n * (K + 1), N){
        // cout << "tmps: " << tmps << endl;
        post_2(i);
        int val; cin >> val;
        answers[i] = (val ^ tmps);
        tmps = (val ^ answers[i - K + 1]);
        // cout << "i: " << i << ", tmps: " << tmps << endl;
    }

    cout << "! ";
    for(auto v: answers){
        cout << v << " ";
    }
    cout << endl;
    cout << flush;
    return 0;
}