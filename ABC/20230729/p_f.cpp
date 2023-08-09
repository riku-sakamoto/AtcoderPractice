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
    priority_queue<LL> cans;
    vector<LL> frees;
    vector<LL> prices;
    REP(i, N){
        int t; LL X; cin >> t >> X;
        if(t == 0){
            frees.push_back(X);
        }
        if(t == 1){
            prices.push_back(X);
        }
        if(t == 2){
            cans.push(X);
        }
    }

    sort(ALL(frees));
    sort(ALL(prices));
    reverse(ALL(prices));
    priority_queue<LL, vector<LL>, greater<LL>> que;
    int n = frees.size();
    auto k = min({M, n});

    int n_can = k;
    REP(i, k){
        que.push(frees[n - 1 - i]);
    }

    LL n_cankiri = 0LL;
    for(auto v: prices){
        LL vtop;
        if(que.size() == 0){
            vtop = 0LL;
        }else{
            vtop = que.top();
        }

        if(n_can == M){
            if(vtop >= v){break;}
            if(n_cankiri == 0){break;}
            que.pop();
            que.push(v);
            n_cankiri -= 1;
            continue;
        }

        if(n_can == M - 1){
            if(n_cankiri == 0){
                if(vtop >= v){break;}
                if(cans.size() == 0){break;}
                n_cankiri = cans.top(); cans.pop();
                que.pop();
                que.push(v);
                n_cankiri -= 1;
                n_can += 1;
                continue;
            }

            que.push(v);
            n_cankiri -= 1;
            n_can += 1;        
            continue;
        }

        if(n_cankiri == 0){
            if(cans.size() == 0){break;}
            n_can += 1;
            n_cankiri = cans.top(); cans.pop();
        }
        
        que.push(v);
        n_cankiri -= 1;
        n_can += 1;
    }
    

    LL ans = 0LL;
    // cout << "n_can: " << n_can << endl;
    while(!que.empty()){
        auto v = que.top(); que.pop();
        ans += v;
    }

    out(ans);

    return 0;
}