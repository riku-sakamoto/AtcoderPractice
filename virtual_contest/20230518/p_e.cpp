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


LL A, M;
pair<LL, LL> tortuise_hare(){
    LL tort = A % M;
    LL hare = ((A % M) * (A % M)) % M;
    while(hare != tort){
        tort = (tort * (A % M)) % M;
        hare = (hare * ((A % M) * (A % M)) % M) % M;
    }

    hare = A % M;
    LL init_l = 0;
    while(hare != tort){
        tort = (tort * (A % M)) % M;
        hare = (hare * (A % M)) % M;
        ++init_l;
    }

    return {init_l, hare};
}

int main(){
    LL X;
    cin >> A >> X >> M;

    auto item = tortuise_hare();
    LL start_cycle, val0;
    tie(start_cycle, val0) = item;

    set<LL> values;
    LL cycle_value;
    LL n_cycle = 0LL;
    LL n_val = 0LL;
    while(true){
        auto n_val = (val0 * (A % M)) % M;
        if(val0 == n_val){
            break;
        }
    }
    return 0;
}