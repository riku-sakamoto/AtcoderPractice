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
const LL INF = 1LL << 30;
struct Edge {
    int to;
    LL w;
    Edge(int to, LL w): to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;


int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    REP(i, H){
        REP(j, W){
            cin >> s[i][j];
        }
    }

    // i, j, pre_color, flip_count
    deque<tuple<int, int, char, int>> que;
    if(s[0][0] == '#'){
        que.push_back({0, 0, '#', 1});
    }else{
        que.push_back({0, 0, '.', 0});
    }
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    vector<vector<int>> counts(H, vector<int>(W, INF));
    while(!que.empty()){
        auto v = que.front(); que.pop_front();
        auto xi = get<0>(v);
        auto yi = get<1>(v);
        auto pre_c = get<2>(v);
        auto count = get<3>(v);

        if(xi == H - 1 && yi == W - 1){
            if(pre_c == s[xi][yi]){
                chmin(counts[xi][yi], count);
                continue;
            }
            if(s[xi][yi] == '#'){
                chmin(counts[xi][yi], count + 1);
            }else{
                chmin(counts[xi][yi], count);
            }
            continue;
        }

        if(counts[xi][yi] <= count){
            continue;
        }
        counts[xi][yi] = count;

        for(auto next_dir: dirs){
            auto next_x = xi + next_dir.first;
            auto next_y = yi + next_dir.second;

            if(next_x >= H || next_y >= W){
                continue;
            }

            auto color = s[next_x][next_y];
            int next_count = count;
            if(color != pre_c && color == '#'){
                next_count += 1;
                que.push_back({next_x, next_y, color, next_count});
            }else{
                que.push_front({next_x, next_y, color, next_count});
            }
        }

    }

    auto ans = counts[H - 1][W - 1];
    out(ans);

    return 0;
}