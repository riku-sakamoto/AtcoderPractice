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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPREV(i,n) for(int i=(n-1);i>=(0);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

bool checkConnect(vector<LL>& circleA, vector<LL>& circleB){
    LL xA = circleA[0];
    LL yA = circleA[1];
    LL rA = circleA[2];

    LL xB = circleB[0];
    LL yB = circleB[1];
    LL rB = circleB[2];

    LL Length2 = (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB);
    LL Diff2 = (rB - rA) * (rB - rA);
    LL R2 = (rA + rB) * (rA + rB);
    if(Length2 <= R2 && Length2 >= Diff2){
        return true;
    }else{
        return false;
    }
}

vector<int> searchCircle(LL x, LL y, vector<vector<LL>>& circles){
    vector<int> target_circles;
    int i = 0;
    for(auto& circle: circles){
        LL cx = circle[0];
        LL cy = circle[1];
        LL r = circle[2];

        LL diff = (x - cx) * (x - cx) + (y - cy) * (y - cy) - r * r;
        if(diff == 0){
            target_circles.push_back(i);
        }
        ++i;
    }
    return target_circles;
}


int main(){
    int N;
    cin >> N;

    LL sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<vector<LL>> circles(N);
    REP(i, N){
        LL x, y, r;
        cin >> x >> y >> r;
        circles[i].push_back(x);
        circles[i].push_back(y);
        circles[i].push_back(r);
    }
    UnionFind container = UnionFind(N);

    REP(i, N){
        FOR(j, i+1, N){
            bool isConnect = checkConnect(circles[i], circles[j]);
            if(isConnect){
                container.unite(i, j);
            }
        }
    }

    vector<int> s_circles = searchCircle(sx, sy, circles);
    vector<int> t_circles = searchCircle(tx, ty, circles);

    for(auto i: s_circles){
        for(auto j: t_circles){
            if(container.same(i, j)){
                yes();
                return 0;
            }
        }
    }

    no();
    return 0;
}