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

int searchMissing(vector<char>& line){
    if(line.size() < 6){return 6;}

    int count_dot = 0;
    REP(i, 6){
        if(line[i] == '.') count_dot+=1;
    }
    int min_count = count_dot;

    FOR(i, 6, line.size()){
        if(line[i] == '.'){
            count_dot+=1;
        }

        if(line[i-6] == '.'){
            count_dot -= 1;
        }

        chmin(min_count, count_dot);
    }
    return min_count;
}

int main(){
    int N;
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N, '.'));
    REP(i, N){
        REP(j, N){
            cin >> S[i][j];
        }
    }

    priority_queue<int, vector<int>, greater<int>> que;

    // row
    REP(i, N){
        int missing = searchMissing(S[i]);
        // cout << missing << endl;
        que.push(missing);
    }

    REP(j, N){
        vector<char> tmp;
        REP(i, N){
            tmp.push_back(S[i][j]);
        }
        int missing = searchMissing(tmp);
        que.push(missing);
    }

    REP(i, N){
        vector<char> tmp;
        REP(j, N){
            if(i+j >= N) continue;
            tmp.push_back(S[i+j][j]);
        }
        int missing = searchMissing(tmp);
        que.push(missing);
    }


    REP(i, N){
        vector<char> tmp;
        REP(j, N){
            if(i+j >= N) continue;
            tmp.push_back(S[j][i+j]);
        }
        int missing = searchMissing(tmp);
        que.push(missing);
    }

    /// reverse
    REP(i, N){
        vector<char> tmp;
        REP(j, N){
            if(i+j >= N) continue;
            tmp.push_back(S[j][N-1-(i+j)]);
            // cout << j << "," << N-1-(i+j) << endl;
        }
        int missing = searchMissing(tmp);
        que.push(missing);
    }

    REP(i, N){
        vector<char> tmp;
        REP(j, N){
            if(i+j >= N) continue;
            tmp.push_back(S[i+j][N-1-j]);
        }
        int missing = searchMissing(tmp);
        que.push(missing);
    }

    if(que.top() <= 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}