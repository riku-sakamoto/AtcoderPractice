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

int main(){
    int N;
    cin >> N;

    vector<LL> S(N, 0);
    vector<LL> T(N, 0);
    REP(i, N){
        cin >> S[i];
    }
    REP(i, N){
        cin >> T[i];
    }

    int startI;
    LL min_val = 1E9 + 1;
    REP(i, N){
        if(T[i] < min_val){
            startI = i;
            min_val = T[i];
        }
    }

    queue<int> que;
    REP(i, N){
        que.push(1);
    }
    
    vector<LL> ans(N, 0);
    ans[startI] = T[startI];
    que.pop();

    LL time = 0;
    while(!que.empty()){
        int nextI;
        if(startI < N - 1){
            nextI = startI + 1;
        }else{
            nextI = 0;
        }

        ans[nextI] = min({T[nextI], ans[startI] + S[startI]});
        startI = nextI;
        que.pop();
    }

    REP(i, N){
        cout << ans[i] << endl;
    }
    return 0;
}