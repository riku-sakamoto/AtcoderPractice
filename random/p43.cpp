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



bool isInMaze(int r, int c, int H, int W){
    if(r >= 0 && r < H && c >= 0 && c < W){
        return true;
    }else{
        return false;
    }
}

bool canMove(int r, int c, vector<vector<char>>& maze){
    if(maze[r][c] == '#'){return false;}
    else{return true;}
}

int getDir(int inc_r, int inc_c){
    if(inc_r == 1 && inc_c== 0){
        return 0;
    }
    if(inc_r == 0 && inc_c== 1){
        return 1;
    }
    if(inc_r == -1 && inc_c== 0){
        return 2;
    }
    if(inc_r == 0 && inc_c== -1){
        return 3;
    }
    return -1;
}

int main(){
    int H, W;
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs;
    cin >> rt >> ct;
    vector<vector<char>> maze(H, vector<char>(W, '.'));
    REP(i, H){
        REP(j, W){
            cin >> maze[i][j];
        }
    }

    vector<pair<int, int>>dirs;
    dirs.push_back({1, 0});
    dirs.push_back({0, 1});
    dirs.push_back({-1, 0});
    dirs.push_back({0, -1});

    deque<tuple<int, int, int, int>> routes;
    int ans = -1;
    routes.push_back({rs-1, cs-1, 0, -1});
    while(!routes.empty()){
        auto route = routes.front();routes.pop_front();
        int r = get<0>(route);
        int c = get<1>(route);
        int p = get<2>(route);
        int dir = get<3>(route);
        if(r == rt-1 && c == ct-1){
            ans = p;
            break;
        }

        for(auto next: dirs){
            int r_next = next.first + r;
            int c_next = next.second + c;
            if(isInMaze(r_next, c_next, H, W) == false) {continue;}
            if(canMove(r_next, c_next, maze) == false){continue;}

            int next_dir = getDir(next.first, next.second);
            if(dir == -1){
                routes.push_front({r_next, c_next, p, next_dir});
                continue;
            }

            if(dir != next_dir){
                routes.push_back({r_next, c_next, p + 1, next_dir});
            }else{
                routes.push_front({r_next, c_next, p, next_dir});
            }
        }
    }


    cout << ans << endl;
    return 0;
}