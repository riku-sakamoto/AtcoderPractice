#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int N;
    cin >> N;
    const int size = 1001;
    vector<vector<int>> Rect(size, vector<int>(size, 0));

    REP(i, N){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        Rect[lx][ly] += 1;
        Rect[rx][ly] += -1;
        Rect[lx][ry] += -1;
        Rect[rx][ry] += 1;

    }

    REP(i, size){
        int sum_row = 0;
        REP(j, size){
            sum_row += Rect[i][j];
            Rect[i][j] = sum_row; 
        }
    }

    REP(j, size){
        int sum_col = 0;
        REP(i, size){
            sum_col += Rect[i][j];
            Rect[i][j] = sum_col; 
        }
    }
    
    // REP(i, size){
    //     REP(j, size){
    //         cout << Rect[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    map<int, int> ans;
    FOR(i, 0, N+1){
        ans[i] = 0;
    }

    REP(i, size){
        REP(j, size){
            ans[Rect[i][j]] += 1;
        }
    }

    FOR(i, 1, N+1){
        cout << ans[i] << endl;
    }
    return 0;
}