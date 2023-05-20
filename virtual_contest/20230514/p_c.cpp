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


bool dfs(string start, map<string, string>& names, map<string, int>& used, set<string>& watched){
    if(names.find(start) == names.end()){
        return true;
    }

    auto next_s = names[start];
    if(watched.find(next_s) != watched.end()){
        used[start] = 1;
        return false;
    }
    watched.insert(next_s);
    used[start] = 1;
    return dfs(next_s, names, used, watched);
}

int main(){
    int N;
    cin >> N;
    map<string, string> names;
    map<string, int> used;
    REP(i, N){
        string S, T;
        cin >> S >> T;
        names[S] = T;
        used[S] = 0;
    }

    for(auto p: used){
        if(p.second == 1){
            continue;
        }

        auto s = p.first;
        set<string> watched;
        auto bl = dfs(s, names, used, watched);
        if(!bl){
            no();
            return 0;
        }
    }

    yes();
    return 0;
}