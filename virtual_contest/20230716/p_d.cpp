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


bool dfs(int pre, int node, vector<pair<int, int>>& values, vector<bool>& seen){
    auto p = values[node];
    seen[node] = true;
    int next = -1;
    if(pre == -100){
        next = p.first;
    }else if(pre == -200){
        next = p.second;
    }
    else{
        if(p.first == pre){
            next = p.second;
        }else{
            next = p.first;
        }
    }
    // if(node == 1){out(next);}

    if(next == -1){
        return false;
    }

    if(seen[next]){
        return true;
    }

    return dfs(node, next, values, seen);

}

int main(){
    int N, M; cin >> N >> M;
    vector<tuple<int, char, int, char>> ropes(M);
    REP(i, M){
        char B, D;
        int A, C; 
        cin >> A >> B >> C >> D;
        --A; --C;
        ropes[i] = {A, B, C, D};
    }

    // R, B
    vector<pair<int, int>> values(N, {-1, -1});
    REP(i, M){
        char B, D;
        int A, C;
        tie(A, B, C, D) = ropes[i];
        if(B == 'R'){values[A].first = C;}
        else{values[A].second = C;}

        if(D == 'R'){values[C].first = A;}
        else{values[C].second = A;}
    }

    int loop_c, non_c;
    loop_c = 0; non_c = 0;
    vector<bool> seen(N, false);
    REP(i, N){
        if(seen[i]){continue;}
        // cout << i << ", " << flag << endl;
        if(values[i].first == -1 && values[i].second == -1){
            ++non_c;
            seen[i] = true;
            continue;
        }

        auto flag = dfs(-100, i, values, seen);
        if(flag){
            ++loop_c;
        }else{
            ++non_c;
            dfs(-200, i, values, seen);
        }
    }
    cout << loop_c << " " << non_c << endl;

    return 0;
}