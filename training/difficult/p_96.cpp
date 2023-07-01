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
    auto n = vec.size();
    REP(i, vec.size() - 1){cout << vec[i] << " ";}
    cout << vec[n - 1] << endl;
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

int H, W;
vector<vector<int>> answers;

void update(int i, int j, vector<vector<int>>& A, vector<pair<int, int>>& dirs){
    if(A[i][j] % 2 == 0){return;}
    for(auto dir: dirs){
        auto ni = i + dir.first;
        auto nj = j + dir.second;

        if(ni < 0 || ni >= H || nj < 0 || nj >= W){
            continue;
        }
        answers.push_back({i + 1, j + 1, ni + 1, nj + 1});
        A[ni][nj] += 1;
        A[i][j] -= 1;
        break;
    }
    return;
}

int main(){
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    REP(i, H){
        REP(j, W){
            cin >> A[i][j];
        }
    }

    vector<pair<int, int>> dirs0 = {{0, 1}, {1, 0}};
    vector<pair<int, int>> dirs1 = {{0, -1}, {1, 0}};
    REP(i, H){
        if(i % 2 == 0){
            REP(j, W){
                update(i, j, A, dirs0);
            }
        }else{
            REPREV(j, W){
                update(i, j, A, dirs1);
            }
        }
    }
    int N = answers.size();
    out(N);
    REP(i, N){
        out_vector(answers[i]);
    }

    // cout << endl;
    // REP(i, H){
    //     out_vector(A[i]);
    // }
    return 0;
}