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

int N;

LL dfs(vector<vector<LL>>& balls, int now, LL count, LL target, LL val){

    if(now == N-1){
        for(LL next_v: balls[now]){
            if(target % next_v != 0)continue;

            if(val*next_v == target){
                count +=1;
            }

        }
        return count;
    }else{
        for(LL next_v: balls[now]){
            if(target % next_v != 0)continue;
            count = dfs(balls, now+1, count, target, next_v*val);
        }
    }

    return count;
}


int main(){
    LL X;
    cin >> N >> X;

    vector<vector<LL>> balls(N, vector<LL>());
    REP(i, N){
        int L;
        cin >> L;
        REP(j, L){
            int a;
            cin >> a;
            balls[i].push_back(a);
        }
    }

    LL ans = dfs(balls, 0, 0, X, 1);

    cout << ans << endl;

    return 0;

    
}