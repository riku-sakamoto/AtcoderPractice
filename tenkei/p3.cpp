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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

vector<vector<int>> G;
int N;
const int INF = (1 << 20);

vector<int> bfs(int init){
    int pos = init;
    queue<int> positions;
    positions.push(pos);
    vector<int> dst(N+1, INF);
    dst[init] = 0;

    while(!positions.empty()){
        int crr = positions.front();
        positions.pop();
        for(int nxt:G[crr]){
            if(dst[nxt]==INF){
                dst[nxt] = dst[crr] + 1;
                positions.push(nxt);
            }
        }
    }

    return dst;
}

int main(){
    cin >> N;
    G.resize(N+1);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dst = bfs(1);
    int max_node = 0;
    int maxlength = 0;
    FOR(i, 1, N+1){
        if(maxlength < dst[i]){
            maxlength = dst[i];
            max_node = i;
        }
    }

    dst = bfs(max_node);
    int max_node_2 = 0;
    maxlength = 0;
    FOR(i, 1, N+1){
        if(maxlength < dst[i]){
            maxlength = dst[i];
            max_node_2 = i;
        }
    }

    cout << maxlength + 1 << endl;
    return 0;
}