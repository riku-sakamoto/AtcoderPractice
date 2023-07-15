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


int Ha, Wa;
int Hb, Wb;
int Hx, Wx;

vector<vector<char>> init_sheet(vector<vector<char>>& sheetA, int H, int W){
    vector<vector<char>> sheetV(H, vector<char>(W, '.'));
    REP(i, Ha){
        REP(j, Wa){
            sheetV[i + Hb + Hx][j + Wb + Wx] = sheetA[i][j];
        }
    }
    return sheetV;
}


int count_black(vector<vector<char>>& sheet){
    int H = sheet.size();
    int W = sheet[0].size();
    int ans = 0;
    REP(i, H){
        REP(j, W){
            if(sheet[i][j] == '#'){++ans;}
        }
    }
    return ans;
}

bool sheet_match(vector<vector<char>>& sheetV, vector<vector<char>>& sheetX){
    int H = sheetV.size();
    int W = sheetV[0].size();

    vector<pair<int, int>> starts;
    REP(i, H){
        REP(j, W){
            if(i + Hx >= H || j + Wx >= W){continue;}
            starts.push_back({i, j});
        }
    }

    for(auto p: starts){
        bool flag = true;
        REP(i, Hx){
            REP(j, Wx){
                if(sheetV[i + p.first][j + p.second] == sheetX[i][j]){continue;}
                else{flag = false;}
            }
        }
        if(flag){return true;}
    }
    return false;
}

int main(){
    cin >> Ha >> Wa;
    vector<vector<char>> sheetA(Ha, vector<char>(Wa));
    REP(i, Ha){
        REP(j, Wa){
            cin >> sheetA[i][j];
        }
    }
    cin >> Hb >> Wb;
    vector<vector<char>> sheetB(Hb, vector<char>(Wb));
    REP(i, Hb){
        REP(j, Wb){
            cin >> sheetB[i][j];
        }
    }
    cin >> Hx >> Wx;
    vector<vector<char>> sheetX(Hx, vector<char>(Wx));
    REP(i, Hx){
        REP(j, Wx){
            cin >> sheetX[i][j];
        }
    }

    auto H = 2 * Hb + 2 * Hx + Ha;
    auto W = 2 * Wb + 2 * Wx + Wa;

    REP(ib, H){
        REP(jb, W){
            auto sheetV = init_sheet(sheetA, H, W);
            if(ib + Hb >= H || jb + Wb >= W){continue;}

            REP(_i, Hb){
                REP(_j, Wb){
                    int i = _i + ib;
                    int j = _j + jb;
                    if(sheetV[i][j] == '#'){continue;}
                    sheetV[i][j] = sheetB[_i][_j];
                }
            }

            auto ok = sheet_match(sheetV, sheetX);
            // cout << ib << ", " << jb << endl;
            // if(ib == Hb && jb == Wb){
            //     REP(i, H){
            //         out_vector(sheetV[i]);
            //     }
            // }
            if(ok){
                auto black_x = count_black(sheetX);
                auto black_v = count_black(sheetV);
                if(black_x == black_v){
                    Yes();
                    return 0;
                }
            }
        }
    }

    No();
    
    return 0;
}