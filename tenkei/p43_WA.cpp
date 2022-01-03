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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

LL large = 1E18;

int main(){
    int H, W;
    cin >> H >> W;
    int rs, cs;
    cin >> rs >> cs;
    int rt, ct;
    cin >> rt >> ct;

    vector<vector<char>> maze(H+1, vector<char>(W+1, '#'));
    vector<vector<LL>> mazeBend1(H+1, vector<LL>(W+1, large));
    vector<vector<LL>> mazeBend2(H+1, vector<LL>(W+1, large));
    vector<vector<LL>> mazeBend3(H+1, vector<LL>(W+1, large));
    vector<vector<LL>> mazeBend4(H+1, vector<LL>(W+1, large));
    FOR(i, 1, H+1){
        FOR(j, 1, W+1){
            cin >> maze[i][j];
        }
    }

    queue<tuple<int, int, int, char>> que;
    que.push({rs, cs, 0, 'z'});
    mazeBend1[rs][cs] = 0;
    mazeBend2[rs][cs] = 0;
    mazeBend3[rs][cs] = 0;
    mazeBend4[rs][cs] = 0;

    vector<pair<int, int>> nextAdd(4);
    nextAdd.push_back({1, 0});
    nextAdd.push_back({0, 1});
    nextAdd.push_back({-1, 0});
    nextAdd.push_back({0, -1});


    while(!que.empty()){
        tuple<int, int, int, char>pos = que.front(); que.pop();
        int rn = get<0>(pos);
        int cn = get<1>(pos);
        int t = get<2>(pos);
        char dir = get<3>(pos);
        // cout << rx << ", " << ry << ", " << t << endl;

        if(rn==rt && cn==ct){
            continue;
        }

        for(auto inc : nextAdd){
            int r_ = rn + inc.first;
            int c_ = cn + inc.second;
            int t_ = t;
            int dir_ = (inc.first != 0)? 'y' : 'x';

            if(inc.first != 0 && dir == 'x'){
                t_ = t + 1;
            }else if (inc.second != 0 && dir == 'y'){
                t_ = t + 1;
            }

            // 必ずしも最短経路になるわけではない
            // 計算量はO

            if(r_ <= H && c_ <= W && r_ >= 0 && c_ >= 0 && maze[r_][c_] != '#'){
                // 既に通った事があっても方向が違えばそのあとに影響する。
                if(mazeBend[r_][c_] > t_){
                    chmin(mazeBend[r_][c_], t_);
                    que.push({r_, c_, t_, dir_});
                }
            }
        }

    }

    cout << mazeBend[rt][ct] << endl;

    return 0;
    
}