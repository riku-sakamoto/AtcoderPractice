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


bool check(vector<int>& nums, vector<vector<int>>& XY, int N){
    REP(i, N-1){
        int now = nums[i];
        int next = nums[i+1];
        if(XY[now][next] == 1){
            return false;
        }
    }
    return true;
}

int calcTime(vector<int>& nums, vector<vector<int>>& A, int N){
    int time = 0;
    REP(i, N){
        int now = nums[i];
        time += A[now][i];
    }
    return time;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    REP(i, N){
        REP(j, N){
            cin >> A[i][j];
        }
    }
    int M;
    cin >> M;
    vector<vector<int>> XY(N, vector<int>(N, 0));
    REP(i, M){
        int x, y;
        cin >>  x >> y;
        XY[x-1][y-1] = 1;
        XY[y-1][x-1] = 1;
    }

    vector<int> nums;
    REP(i, N) nums.push_back(i);
    int ans = INT_MAX;
    do{
        bool ok = check(nums, XY, N);
        if(ok == false) continue;
        int time = calcTime(nums, A, N);
        chmin(ans, time);
    }while(next_permutation(ALL(nums)));

    if (ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}