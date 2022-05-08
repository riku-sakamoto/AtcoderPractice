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

int M = 5001;

int calcAccum2DSum(vector<vector<LL>> &mat, int x, int y, int K)
{

    int r_x = min({M-1, x + K});
    int r_y = min({M-1, y + K});
    // cout << r_x << ", " << r_y << ", " << x << ", " << y << endl;

    // return mat.at(r_x).at(r_y) - mat.at(r_x).at(y-1) - mat.at(x-1).at(r_y) + mat.at(x-1).at(y-1);

    return mat[r_x][r_y] - mat[r_x][y - 1] - mat[x - 1][r_y] + mat[x - 1][y - 1];
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<vector<LL>> memos(M, vector<LL>(M, 0));
    REP(i, N){
        int a, b;
        cin >> a >> b;
        memos[a][b] += 1;
    }

    REP(i, M){
        FOR(j, 1, M){
            memos[i][j] += memos[i][j-1];
        }
    }

    REP(j, M){
        FOR(i, 1, M){
            memos[i][j] += memos[i-1][j];
        }
    }


    int count = 0;
    FOR(x, 1, M){
        FOR(y, 1, M){
            int _count = calcAccum2DSum(memos, x, y, K);
            chmax(count, _count);
            // cout << count << endl;
        }
    }
 

    cout << count << endl;
    return 0;
}