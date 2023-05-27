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


int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> maze(H, vector<char>(W, '.'));
    vector<vector<int>> used(H, vector<int>(W, 0));
    REP(i, H){
        REP(j, W){
            cin >> maze[i][j];
        }
    }

    auto N = min({H, W});
    map<int, int> answers;


    vector<pair<int, int>> dirs = {{1, 1}, {1, -1}};
    
    REP(i, H){
        REP(j, W){
            if(maze[i][j] == '.'){continue;}

            if(used[i][j] == 1){continue;}

            pair<int, int> dir = {0, 0};
            for(auto d: dirs){
                auto next_i = i + d.first;
                auto next_j = j + d.second;
                if(next_i < 0 || next_i >= H || next_j < 0 || next_j >= W){
                    continue;
                }
                auto k = maze[next_i][next_j];
                if(k == '.'){continue;}
                if(k == '#'){
                    dir = d;
                    break;
                }
            }
            // cout << i << ", "<< j << endl;
            // cout << dir.first << "-" << dir.second << endl;
            if(dir.first == 0 && dir.second == 0){
                continue;
            }

            int size = 1;
            bool in_count = true;
            auto next_i = i;
            auto next_j = j;
            used[next_i][next_j] = 1;
            while(true){
                next_i = next_i + dir.first;
                next_j = next_j + dir.second;
                if(next_i < 0 || next_i >= H || next_j < 0 || next_j >= W){
                    break;
                }

                auto k = maze[next_i][next_j];
                if(k == '.'){
                    break;
                }

                if(used[next_i][next_j] == 1){
                    in_count = false;
                }
                ++size;
                used[next_i][next_j] = 1;
            }
            if (in_count){
                size = (size - 1) / 2;
                answers[size] += 1;
            }
        }
    }
    
    FOR(i, 1, N + 1){
        cout << answers[i] << " ";
    }
    cout << endl;
    return 0;
}