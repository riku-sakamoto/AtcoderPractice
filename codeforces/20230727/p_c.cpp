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


string mul_str(const string& s,int k){
    if(k == 0) return "";
    string p = mul_str(s + s, k / 2); // (s+s)*(k/2);
    if(k%2 == 1) p+=s;
    return p;
}


// int solve(){
//     int n, m; cin >> n >> m;
//     string s; cin >> s;
//     set<string> vals; vals.insert(s);
//     vector<int> zeros(n + 1, 0);
//     vector<int> ones(n + 1, 0);

//     REP(i, n){
//         if(s[i] == '0'){
//             zeros[i + 1] = zeros[i] + 1;
//             ones[i + 1] = ones[i];
//         }else{
//             zeros[i + 1] = zeros[i];
//             ones[i + 1] = ones[i] + 1;
//         }
//     }
//     REP(i, m){
//         int l, r; cin >> l >> r; --l; --r;
//         auto s1 = str_slice(0, l, s);
//         auto s3 = str_slice(r + 1, n, s);

//         int n_ones = ones[r + 1] - ones[l];
//         int n_zeros = zeros[r + 1] - zeros[l];
//         // cout << "n_ones: " << n_ones << endl;
//         // cout << "n_zeros: " << n_zeros << endl;
//         auto s2 = mul_str("0", n_zeros) + mul_str("1", n_ones);
//         auto stmp = s1 + s2 + s3;
//         cout << "stmp: " << stmp << endl;
//         vals.insert(stmp);
//     }

//     int ans = vals.size();
//     return ans;
// }


struct StringDecorator
{
    string S;
    int N;
    // rights[i][j]: the index where i-th char exists larger than j-th index
    vector<vector<int>> rights;

    // lefts[i][j]: the index where i-th char exists smaller than j-th index
    vector<vector<int>> lefts;

    // before initialization, converting to each char in s to int
    // example: for(auto& c: s){c -= '0';} or {c -= 'a'};
    StringDecorator(string s){
        S = s; N = s.size();
        rights = vector<vector<int>>(2, vector<int>(N));
        lefts = vector<vector<int>>(2, vector<int>(N));
        initialize_position();
    }
    void initialize_position(){
        // num. of alphabets is 26.
        // initialize last index and first index;
        REP(c, 2){rights[c][N - 1] = N; lefts[c][0] = -1;};
        REPREV(i, N){
            REP(c, 2){
                if(i + 1 < N) {rights[c][i] = rights[c][i + 1];}
            }
            rights[S[i]][i] = i;
        }
        REP(i, N){
            REP(c, 2){
                if(i > 0){lefts[c][i] = lefts[c][i - 1];}
            }
            lefts[S[i]][i] = i;
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

    // search index of c smaller than idx
    int search_left(int c, int idx){
        if(idx == -1){return -1;}
        if(idx == N){
            if(S[N - 1] == c){return N - 1;}
            idx = N - 1;
        }
        return lefts[c][idx];
    }

};


int solve(){
    int n, m; cin >> n >> m;
    string tmpS; cin >> tmpS;

    // vector<int> zero_idx(n);
    // vector<int> one_idx(n);
    
    // zero_idx[0] = -1;
    // REP(i, n){
    //     if(i > 0){zero_idx[i] = zero_idx[i - 1];}
    //     if(tmpS[i] == '0'){zero_idx[i] = i;}
    // }
    // one_idx[n - 1] = n;
    // REPREV(i, n){
    //     if(i + 1 < n){one_idx[i] = one_idx[i + 1];}
    //     if(tmpS[i] == '1'){one_idx[i] = i;}
    // }

    for(auto& c: tmpS){c -= '0';}
    StringDecorator decorator(tmpS);
    // out_vector(ones);

    set<pair<int, int>> vals;
    REP(i, m){
        int l, r; cin >> l >> r; --l; --r;

        auto one_idx = decorator.search_right(1, l);
        auto zero_idx = decorator.search_left(0, r);

        // auto l_idx = one_idx[l];
        // auto r_idx = zero_idx[r];
        // if(l_idx > r_idx){
        //     vals.insert({-1, n});
        //     continue;
        // }
        // vals.insert({l_idx, r_idx});
        // cout << l << ", " << r << endl;
        // cout << one_idx << ", " << zero_idx << endl;
        // cout << " ---- " << endl;
        if(one_idx >= zero_idx){
            vals.insert({-1, n});
            continue;
        }
    //     // if(one_idx == inf || zero_idx == -1){continue;}
    //     // cout << one_idx << ", " << zero_idx << endl;
        vals.insert({one_idx, zero_idx});
    }

    int ans = vals.size();
    return ans;
}


int main(){
    int t; cin >> t;
    vector<int> answers;
    REP(_, t){
        auto k = solve();
        answers.push_back(k);
    }

    for(auto v: answers){
        out(v);
    }
    return 0;
}