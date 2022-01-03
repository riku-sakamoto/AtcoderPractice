#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
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

map<int, int> color;

int dfs(vector<vector<int>>& tree, int now, int sign){

    color[now] = sign;
    for(int dst : tree[now]){
        if(color[dst] != 0){continue;}
        dfs(tree, dst, sign*-1);
    }
    return 0;
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> tree(N+1);
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        color[a] = 0;
        color[b] = 0;
    }

    dfs(tree, 1, 1);

    vector<int> G1, G2;
    for(auto itr=color.begin(); itr!=color.end(); ++itr){
        int key = itr->first;
        int val = itr->second;
        if(val == 1){
            G1.push_back(key);
        }else{
            G2.push_back(key);
        }
    }

    if(G1.size() > G2.size()){
        REP(i, N/2){
            cout << G1[i] << " ";
        }
    }else{
        REP(i, N/2){
            cout << G2[i] << " ";
        }
    }
    cout << endl;
    return 0;
    
}