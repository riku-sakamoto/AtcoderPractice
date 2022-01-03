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

pair<int, int> DIRS[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> steps;

int H;
int W;
int is = 0;
int js = 0;

bool InArea(int i, int j){
    if(i < H && i >=0 && j < W && j >= 0){
        return true;
    }else{
        return false;
    }
}

void dfs(int i, int j, vector<vector<char>>& cij, int step, vector<vector<bool>>& visited, pair<int,int> prePoint){
    
    if(step!=0){
        visited[i][j] = true;
    }

    for(pair<int, int> dirs: DIRS){
        int nextI = i + dirs.first;
        int nextJ = j + dirs.second;
        // cout << nextI << "," << nextJ << endl;
        if((prePoint.first == nextI) && (prePoint.second == nextJ)) continue;
        if (InArea(nextI, nextJ) == false) continue;
        if (cij[nextI][nextJ] == '#') continue;
        if (visited[nextI][nextJ] == true) continue;
        if((nextI == is) && (nextJ == js)){
            // cout << step << endl;
            steps.push_back(step + 1);
            continue;
        }
        // cout << "one step" << endl;

        dfs(nextI, nextJ, cij, step + 1, visited, {i, j});

    }
}

int main(){
    cin >> H >> W;
    vector<vector<char>> cij(H, vector<char>(W, 0));
    REP(i, H){
        REP(j, W){
            cin >> cij[i][j];
        }
    }

    int ans = 0;

    REP(i, H){
        REP(j, W){
            int start = cij[i][j];
            vector<vector<bool>> visited(H, vector<bool>(W, false));
            steps.clear();
            if(start == '#')continue;
            is = i;
            js = j;
            dfs(i, j, cij, 0, visited, {-1, -1});

            if(steps.size() == 0) continue;
            int maxSteps = *max_element(ALL(steps));
            chmax(ans, maxSteps);
        }
    }

    if(ans == 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;

    
}