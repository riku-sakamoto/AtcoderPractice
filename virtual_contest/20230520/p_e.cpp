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
const LL INF = 1LL << 60;
struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;


int main(){
    int N, K;
    cin >> N >> K;

    int max_v = ((N - 1) * (N - 2)) / 2;
    if(max_v < K){
        out(-1);
        return 0;
    }

    vector<pair<int, int>> edges;
    REP(i, N){
        if(i == 0){
            continue;
        }
        edges.push_back({1, i + 1});
    }

    int v = max_v;
    bool finished = false;
    FOR(i, 1, N){
        FOR(j, i + 1, N){
            if(v == K){
                finished = true;
                break;
            }
            edges.push_back({i + 1, j + 1});
            --v;
        }
        if(finished){
            break;
        }
    }
    
    int m = edges.size();
    out(m);
    for(auto p: edges){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}