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


int main(){
    int N, M; cin >> N >> M;

    vector<vector<char>> code(N, vector<char>(M));
    REP(i, N){
        REP(j, M){
            cin >> code[i][j];
        }
    }

    vector<pair<int, int>> answers;
    REP(i, N){
        if(i + 8 >= N){continue;}
        REP(j, M){
            if(j + 8 >= M){continue;}

            bool flag = true;
            FOR(ki, i, i + 3){
                FOR(kj, j, j + 3){
                    if(code[ki][kj] == '#'){continue;}
                    flag = false;
                }
            }
            FOR(ki, i, i + 4){
                auto kj = j + 3;
                if(code[ki][kj] == '.'){continue;}
                flag = false;
            }
            FOR(kj, j, j + 4){
                auto ki = i + 3;
                if(code[ki][kj] == '.'){continue;}
                flag = false;
            }
            if(!flag){continue;}

            FOR(ki, i + 6, i + 9){
                FOR(kj, j + 6, j + 9){
                    if(code[ki][kj] == '#'){continue;}
                    flag = false;
                }
            }
            FOR(ki, i + 5, i + 9){
                auto kj = j + 5;
                if(code[ki][kj] == '.'){continue;}
                flag = false;
            }
            FOR(kj, j + 5, j + 9){
                auto ki = i + 5;
                if(code[ki][kj] == '.'){continue;}
                flag = false;
            }

            if(!flag){continue;}

            answers.push_back({i, j});
        }
    }

    for(auto p: answers){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}