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
    int H, W; cin >> H >> W;
    vector<vector<char>> colors(H, vector<char>(W));
    REP(i, H){
        REP(j, W){
            cin >> colors[i][j];
        }
    }
    vector<map<char, int>> row_kinds(H);
    vector<map<char, int>> col_kinds(W);
    REP(i, H){
        map<char, int> counts;
        for(auto c: colors[i]){
            counts[c] += 1;
        }
        row_kinds[i] = counts;
    }

    REP(j, W){
        map<char, int> counts;
        REP(i, H){
            auto c = colors[i][j];
            counts[c] += 1;
        }
        col_kinds[j] = counts;
    }

    REP(_, H + W){
        map<char, int> row_erase_chars;
        map<char, int> col_erase_chars;
        REP(i, H){
            if(row_kinds[i].size() != 1){continue;}
            auto p = *row_kinds[i].begin();

            if(p.second >= 2){
                row_erase_chars[p.first] += 1;
                row_kinds[i].erase(p.first);
            }
        }

        REP(j, W){
            if(col_kinds[j].size() != 1){continue;}
            auto p = *col_kinds[j].begin();

            if(p.second >= 2){
                col_erase_chars[p.first] += 1;
                col_kinds[j].erase(p.first);
            }

        }

        if(row_erase_chars.size() == 0 && col_erase_chars.size() == 0){
            break;
        }

        REP(j, W){
            for(auto p: row_erase_chars){
                if(col_kinds[j].find(p.first) == col_kinds[j].end()){continue;}
                col_kinds[j][p.first] -= p.second;
                if(col_kinds[j][p.first] == 0){
                    col_kinds[j].erase(p.first);
                }
            }

        }

        REP(i, H){
            for(auto p: col_erase_chars){
                if(row_kinds[i].find(p.first) == row_kinds[i].end()){continue;}
                row_kinds[i][p.first] -= p.second;
                if(row_kinds[i][p.first] == 0){
                    row_kinds[i].erase(p.first);
                }
            }
        }
        
        
        // REP(j, W){
        //     for(auto p: col_kinds[j]){
        //         cout << j << ", " << p.first << ", " << p.second << endl;
        //     }
        // }
    }

    int ans = 0;
    REP(i, H){
        for(auto p :row_kinds[i]){
            // cout << i << ", " << p.first << ", " << p.second << endl;
            if(p.second > 0){
                ans += p.second;
            }
        }
    }

    // REP(j, W){
    //     for(auto p :col_kinds[j]){
    //         cout << j << ", " << p.first << ", " << p.second << endl;
    //     }

    // }

    out(ans);
    return 0;
}