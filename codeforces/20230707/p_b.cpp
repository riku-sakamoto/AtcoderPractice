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


char solve(){
    vector<vector<char>> maze(3, vector<char>(3));
    REP(i, 3){
        REP(j, 3){
            cin >> maze[i][j];
        }
    }

    REP(i, 3){
        if(maze[i][0] == maze[i][1] && maze[i][1] == maze[i][2]){
            if(maze[i][0] == '.'){continue;}
            return maze[i][0];
        }
    }
    REP(j, 3){
        if(maze[0][j] == maze[1][j] && maze[1][j] == maze[2][j]){
            if(maze[0][j] != '.'){
                return maze[0][j];
            }
            
        }
    }
    if(maze[0][0] == maze[1][1] && maze[1][1] == maze[2][2]){
        if(maze[0][0] != '.'){
            return maze[0][0];
        }
    }
    if(maze[0][2] == maze[1][1] && maze[1][1] == maze[2][0]){
        if(maze[0][2] != '.'){
            return maze[0][2];
        }
        
    }

    // int count = 0;
    // REP(i, 3){
    //     REP(j, 3){
    //         if(maze[i][j] == '.'){++count;}
    //     }
    // }
    // char next_c;
    // int idx = 9 - count;
    // if(idx % 3 == 1){next_c = 'X';}
    // else if(idx % 3 == 2){next_c = 'O';}
    // else{next_c = '+';}

    // REP(i, 3){
    //     REP(j, 2){
    //         if(maze[i][j] == maze[i][j + 1] && maze[i][j] == next_c){
    //             return next_c;
    //         }
    //     }
    // }
    // REP(i, 2){
    //     REP(j, 3){
    //         if(maze[i][j] == maze[i + 1][j] && maze[i][j] == next_c){
    //             return next_c;
    //         }
    //     }
    // }

    // REP(i, 2){
    //     if(maze[i][i] == maze[i+1][i+1] && maze[i][i] == next_c){
    //         return next_c;
    //     }
    // }

    // REP(i, 2){
    //     if(maze[i][2-i] == maze[i+1][1-i] && maze[i][2-i] == next_c){
    //         return next_c;
    //     }
    // }
    return 'A';

}


int main(){
    int T; cin >> T;
    vector<string> answers;
    REP(_, T){
        auto c = solve();
        if(c == 'A'){
            answers.push_back("DRAW");
        }else{
            string s = {c};
            answers.push_back(s);
        }
    }

    for(auto v: answers){
        out(v);
    }

    

    return 0;
}