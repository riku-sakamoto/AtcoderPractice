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


int getDir(pair<int, int> move){
    if(move.first == 1){
        return 0;
    }else if(move.first == -1){
        return 1;
    }else if(move.second == 1){
        return 2;
    }else if(move.second == -1){
        return 3;
    }else{
        return -1;
    }
}


int main(){
    int H, W;
    cin >> H >> W;
    int rs, cs;
    cin >> rs >> cs;
    int rt, ct;
    cin >> rt >> ct;

    int INF = 1012345678;

    vector<vector<char>> maze(H+1, vector<char>(W+1, '#'));
    vector<vector<vector<int>>> mazeCount(H+1, vector<vector<int>>(W+1, vector<int>(4, INF)));
    FOR(i, 1, H+1){
        FOR(j, 1, W+1){
            cin >> maze[i][j];
        }
    }

    deque<tuple<int, int, int, int>> que;
    que.push_back({rs, cs, 0, 0});
    que.push_back({rs, cs, 0, 1});
    que.push_back({rs, cs, 0, 2});
    que.push_back({rs, cs, 0, 3});
    mazeCount[rs][cs][0] = 0;
    mazeCount[rs][cs][1] = 0;
    mazeCount[rs][cs][2] = 0;
    mazeCount[rs][cs][3] = 0;

    vector<pair<int, int>> nextMove(4);
    nextMove.push_back({1, 0});
    nextMove.push_back({0, 1});
    nextMove.push_back({-1, 0});
    nextMove.push_back({0, -1});

    priority_queue<int, vector<int>, greater<int>> answers;

    while(!que.empty()){
        tuple<int, int, int, int> pos = que.front(); que.pop_front();
        int r_ = get<0>(pos);
        int c_ = get<1>(pos);
        int p_ = get<2>(pos);
        int dir_ = get<3>(pos);

        if(r_ == rt && c_ == ct){
            continue;
        }

        for(auto move: nextMove){
            int next_r = r_ + move.first;
            int next_c = c_ + move.second;
            if(next_r < 0 || next_r > H) continue;
            if(next_c < 0 || next_c > W) continue;

            if(maze[next_r][next_c] == '#') continue;

            int next_dir = getDir(move);
            int next_p = (dir_ == next_dir)? p_ : p_ + 1;

            if(mazeCount[next_r][next_c][next_dir] > next_p){
                mazeCount[next_r][next_c][next_dir] = next_p;
                if(next_p == p_){
                    que.push_front({next_r, next_c, next_p, next_dir});
                }else{
                    que.push_back({next_r, next_c, next_p, next_dir});
                }
            }
        }

    }

    // vector<int> _answers = mazeCount[rt][ct];
    int ans = *min_element(ALL(mazeCount[rt][ct]));
    cout << ans << endl;
    return 0;
}