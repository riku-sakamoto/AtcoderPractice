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
string str_slice(int i, int j, string& S){
    int n = j - i;
    return S.substr(i, n);
}
using Graph = vector<vector<Edge>>;
const LL INF = 1LL << 60;
const int inf = INT_MAX / 2;

vector<LL> dijkstra(int start, int N, Graph& G){
    // vector<bool> used(N, false);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> que;
    vector<LL> dist(N, INF);
    que.push({0, start});
    dist[start] = 0;

    while(!que.empty()){
        // 未探索のノードの内最小距離のノードを探す
        auto p = que.top(); que.pop();
        int min_v = p.second;
        LL d = p.first;

        // 確定済みのノードに関する情報が入る可能性がある．usedリストを使用しないため．
        if(d > dist[min_v])continue;

        // min_vを始点とした各辺を緩和する
        for(auto e: G[min_v]){
            if(dist[e.to] > dist[min_v] + e.w){
                chmin(dist[e.to], dist[min_v] + e.w);
                que.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10, 0));
    Graph G(10);
    REP(i, 10){
        REP(j, 10){
            LL val;
            cin >> val;
            Edge edge = {j, val};
            G[i].push_back(edge);
        }
    }

    vector<LL> to_one(10, INF);
    REP(i, 10){
        auto dist = dijkstra(i, 10, G);
        to_one[i] = dist[1];
    }

    vector<vector<int>> A(H, vector<int>(W, 0));
    REP(i, H){
        REP(j, W){
            cin >> A[i][j];
        }
    }

    LL ans = 0LL;
    REP(i, H){
        REP(j, W){
            if(A[i][j] == -1){continue;}
            ans += to_one[A[i][j]];
        }
    }
    out(ans);
    return 0;
}