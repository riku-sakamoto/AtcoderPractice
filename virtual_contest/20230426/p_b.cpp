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

int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> Points = vector<vector<int>>(N, vector<int>(3, 0));
    REP(i, N){
        REP(j, 3){
            cin >> Points[i][j];
        }
    }

    priority_queue<pair<int, int>> que;
    REP(i, N){
        int p = Points[i][0] + Points[i][1] + Points[i][2];
        que.push({p, i});
    }

    vector<bool> answers(N, false);
    int last = -1;
    REP(i, K){
        auto item = que.top(); que.pop();
        answers[item.second] = true;
        last = item.first;
    }

    FOR(i, K, N){
        auto item = que.top(); que.pop();
        if (last <= item.first + 300){
            answers[item.second] = true;
        }
    }

    REP(i, N){
        if (answers[i]){
            yes();
        }else{
            no();
        }
    }
    
    return 0;
}