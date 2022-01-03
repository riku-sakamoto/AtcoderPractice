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

int main(){
    int N;
    cin >> N;

    vector<vector<int>> map(N, vector<int>(N, 0));
    vector<int> visited(N, 0);
    REP(i,N-1){
        int ai, bi;
        cin >> ai >> bi;
        map[ai-1][bi-1] = 1;
        map[bi-1][ai-1] = 1;
    }

    queue<int> ans;
    ans.push(1);

    int pre = 1;
    int now = 1;
    while(true){
        bool ok = false;
        int dst;

        REP(i,N){
            if(map[now-1][i] == 0){continue;}
            else{
                if(visited[i] == 0 && i+1 != pre){
                    dst = i + 1;
                    ok = true;
                    break;
                }
            }
        }

        if(ok == false){
            if(now == 1)break;
            else{
                dst = visited[now-1];
            }
        }

        ans.push(dst);
        if(visited[dst -1] == 0){
            visited[dst -1] = now;
        }

        pre = now;
        now = dst;

    }

    while (!ans.empty()){
        int a = ans.front();
        cout << a << " ";
        ans.pop();
    }
    cout << "" << endl;
    
    return 0;
}