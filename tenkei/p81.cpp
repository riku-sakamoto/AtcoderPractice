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

    int max_x = min({M, x + K});
    int max_y = min({M, y + K});

    return mat[max_x][max_y] - mat[max_x][y - 1] - mat[x - 1][max_y] + mat[x - 1][y - 1];
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<vector<LL>> memos(M, vector<LL>(M, 0));
    vector<pair<int,int>> students(N);
    REP(i, N){
        int a, b;
        cin >> a >> b;
        memos[a][b] += 1;
        students[i] = {a, b};
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
    REP(i, N){
        int x = students[i].first;
        int y = students[i].second;
        int _count = calcAccum2DSum(memos, x, y, K);
        chmax(count, _count);
    }
 

    cout << count << endl;
    return 0;
}