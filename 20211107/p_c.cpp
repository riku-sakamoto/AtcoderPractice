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

LL dfs(map<int, vector<int>>& mapSkill, vector<LL>& Times, vector<bool>& Skilled, int now, LL t){
    if(Skilled[now] == true){
        return t;
    }

    Skilled[now] = true;
    if(mapSkill[now].size() == 0){
        return t + Times[now];
    }

    t += Times[now];
    for(auto next : mapSkill[now]){
        // cout << "next: " << next << endl;
        t = dfs(mapSkill, Times, Skilled, next, t);
    }
    return t;
}

int main(){
    int N;
    cin >> N;

    vector<LL> Ti(N+1, 0);
    vector<bool> Skilled(N+1, false);
    map<int, vector<int>> Aijmap;

    REP(i, N){
        cin >> Ti[i+1];
        int k;
        cin >> k;
        vector<int> aij;
        REP(j, k){
            int tmpk;
            cin >> tmpk;
            aij.push_back(tmpk);
        }
        Aijmap[i+1] = aij;
    }

    LL ans = dfs(Aijmap, Ti, Skilled, N, 0LL);
    cout << ans << endl;
    return 0;
    
}