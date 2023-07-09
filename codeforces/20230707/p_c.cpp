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

int solve(){
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<LL>> times(n, vector<LL>(m, 0LL));
    REP(i, n){
        REP(j, m){
            cin >> times[i][j];
        }
        sort(ALL(times[i]));
    }
    // cout << "vectors--" << endl;
    // REP(i, n){
    //     out_vector(times[i]);
    // }
    // cout << "---vectors" << endl;

    // 引数 l が優先度の低い要素であるときに true を返却
    auto comp = [](tuple<int, LL, int> l, tuple<int, LL, int> r){
        if(get<0>(l) < get<0>(r)){
            return true;
        }
        else if(get<0>(l) > get<0>(r)){
            return false;
        }

        if(get<1>(l) < get<1>(r)){
            return false;
        }
        else if (get<1>(l) > get<1>(r)){
            return true;
        }

        if(get<2>(l) > get<2>(r)){
            return true;
        }

        return false;
    };

    priority_queue<
        tuple<int, LL, int>,
        vector<tuple<int, LL, int>>,
        decltype(comp)
    > que(comp);

    REP(i, n){
        int solved = 0;
        LL elapsed = 0LL;
        LL penatly = 0LL;
        REP(j, m){
            if(elapsed + times[i][j] > h){break;}
            elapsed += times[i][j];
            penatly += elapsed;
            solved += 1;
        }

        que.push({solved, penatly, i});
    }

    int ans = 0;
    while(!que.empty()){
        auto v = que.top(); que.pop();
        // cout << get<0>(v) << ", " << get<1>(v) << ", " << get<2>(v) << endl;
        ++ans;
        if(get<2>(v) == 0){
            return ans;
        }
    }
    return ans;
}

int main(){
    int T; cin >> T;
    vector<int> answers;
    REP(_, T){
        auto v = solve();
        answers.push_back(v);
    }

    for(auto v: answers){
        out(v);
    }
    return 0;
}