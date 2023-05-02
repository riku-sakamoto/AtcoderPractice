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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int N;
priority_queue<LL> que;


LL pow10(int n){
    LL val = 1LL;
    REP(i, n){
        val *= 10LL; 
    }
    return val;
}

void dfs(vector<vector<int>>& A, int posX, int posY, LL point, int n, pair<int, int>& dir){

    if (n == 0){
        que.push(point);
        return;
    }

    int val = A[posX][posY];

    LL new_point = point + val * pow10(n - 1);

    int new_posX = posX + dir.first;
    int new_posY = posY + dir.second;

    if (new_posX >= N ){
        new_posX = new_posX % N;
    }
    if (new_posY >= N){
        new_posY = new_posY % N;
    }

    if (new_posX < 0){
        new_posX = N + new_posX;
    }
    if(new_posY < 0){
        new_posY = N + new_posY;
    }

    dfs(A, new_posX, new_posY, new_point, n - 1, dir);

}

int main(){
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    REP(i, N){
        string S;
        cin >> S;
        REP(j, S.size()){
            int val = S[j] - '0';
            A[i][j] = val;
        }
    }

    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    REP(i, N){
        REP(j, N){
            for(auto dir: dirs){
                LL point = 0LL;
                dfs(A, i, j, point, N, dir);
            }
        }
    }

    LL ans = que.top();
    cout << ans << endl;

    return 0;
}