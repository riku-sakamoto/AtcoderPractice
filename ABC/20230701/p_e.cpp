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


int main(){
    int N; cin >> N;
    vector<int> A(N);
    REP(i, N){cin >> A[i];}
    string S; cin >> S;

    vector<vector<int>> pos_M(3, vector<int>(N, 0));
    vector<vector<int>> pos_X(3, vector<int>(N, 0));

    if(S[0] == 'M'){
        pos_M[A[0]][0] = 1;
    }
    FOR(i, 1, N){
        REP(j, 3){
            if(S[i] != 'M'){
                pos_M[j][i] = pos_M[j][i - 1];
                continue;
            }
            int v = (j == A[i])? 1 : 0;
            pos_M[j][i] = pos_M[j][i - 1] + v;
        }
    }


    if(S[N - 1] == 'X'){
        pos_X[A[N - 1]][N - 1] = 1;
    }
    REPREV(i, N){
        if(i == N - 1){continue;}
        REP(j, 3){
            if(S[i] != 'X'){
                pos_X[j][i] = pos_X[j][i + 1];
                continue;
            }

            int v = (j == A[i])? 1: 0;
            pos_X[j][i] = pos_X[j][i + 1] + v;
        }
    }

    LL ans = 0LL;
    FOR(i, 1, N - 1){
        if(S[i] != 'E'){continue;}
        auto v = A[i];
        REP(j, 3){
            REP(k, 3){
                auto m = pos_M[j][i - 1];
                auto x = pos_X[k][i + 1];
                set<int> vals = {j, k, v};
                REP(y, 4){
                    if(vals.find(y) == vals.end()){
                        ans += (LL)m * (LL)x * (LL)y;
                        break;
                    }
                }
            }
        }
    }
    out(ans);
    return 0;
}