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
    if(ptr == vec.end()){
        return -1;
    }
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> int larger_than(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    if(ptr == vec.end()){
        return -1;
    }
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
using Graph = vector<vector<Edge>>;
const LL INF = 1LL << 60;
const int inf = INT_MAX / 2;

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


int main(){
    int N;
    string S;
    cin >> N >> S;

    for(auto &c: S){
        c -= '0';
    }
    StringDecorator s_deco(S);
    
    int ans = 0;
    REP(i, 10) REP(j, 10) REP(k, 10){
        int idx = -1;
        idx = s_deco.search_right(i, idx);
        idx = s_deco.search_right(j, idx);
        idx = s_deco.search_right(k, idx);

        if(idx < inf){
            ++ans;
        }
    }
    out(ans);
    return 0;
}