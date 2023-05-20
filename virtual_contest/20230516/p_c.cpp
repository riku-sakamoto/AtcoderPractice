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
template<typename T> T larger_equal(vector<T>& vec, T val){
    auto ptr = lower_bound(ALL(vec), val);
    if(ptr == vec.end()){
        return T(-1);
    }
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> T larger_than(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    if(ptr == vec.end()){
        return T(-1);
    }
    int idx = ptr - vec.begin();
    return idx;
}
template<typename T> T lower_equal(vector<T>& vec, T val){
    auto ptr = upper_bound(ALL(vec), val);
    int idx = ptr - vec.begin() - 1;
    return idx;
}
template<typename T> T lower_than(vector<T>& vec, T val){
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

string str_slice(int i, int j, string& S){
    int n = j - i;
    return S.substr(i, n);
}


int main(){
    int N;
    string S;
    cin >> N >> S;

    if(N % 2 == 1){
        out(-1);
        return 0;
    }
    int n = N / 2;

    map<string , int> counts;
    for(int j=0; j<N; j+=n){
        auto v = str_slice(j, j + n, S);
        counts[v] += 1;
    }

    string target;
    int count = 0;
    for(auto item: counts){
        if(count < item.second){
            target = item.first;
        }
    }

    int changes = 0;
    for(int j=0; j<N; j+=n){
        auto v = str_slice(j, j + n, S);
        REP(k, n){
            if(v[k] != target[k]){
                changes += 1;
            }
        }
    }

    out(changes);
    return 0;
}