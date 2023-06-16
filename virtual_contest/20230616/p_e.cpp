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

int find_idx(char v, string vals){
    int n = vals.size();
    REP(i, n){
        if(vals[i] == v){return i;}
    }
    return -1;
}

int main(){
    int M; cin >> M;
    int N = 9;
    vector<vector<int>> edges(N);
    REP(i, M){
        int u, v; cin >> u >> v; --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> start(9, 9);
    REP(i, 8){
        int k; cin >> k; --k;
        start[k] = (i + 1);
    }
    // out_vector(start);

    string s;
    for(auto c: start){
        s.push_back('0' + c);
    }
    map<string, int> counts;
    counts[s] = 0;

    string ans = "123456789";
    queue<pair<string, int>> que;
    que.push({s, 0});

    while(!que.empty()){
        auto stmp = que.front(); que.pop();

        auto idx = find_idx('9', stmp.first);
        for(auto p: edges[idx]){
            swap(stmp.first[idx], stmp.first[p]);
            if(counts.find(stmp.first) != counts.end()){
                chmin(counts[stmp.first], stmp.second + 1);
            }else{
                counts[stmp.first] = stmp.second + 1;
                que.push({stmp.first, stmp.second + 1});
            }
            if(stmp.first == ans){
                out(counts[ans]);
                return 0;
            }
            swap(stmp.first[idx], stmp.first[p]);
        }
    }

    if(counts.find(ans) != counts.end()){
        out(counts[ans]);
    }else{
        out(-1);
    }
    return 0;
}