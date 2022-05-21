#define _GLIBCXX_DEBUG
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
    int N, M;
    cin >> N >> M;
    queue<int> que;
    vector<queue<int>> A(M); // 筒
    // 先頭に存在する番号iのボールの数
    vector<vector<int>> mem(N);

    REP(i,M){
        int k;
        cin >> k;
        REP(j,k){
            int a;
            cin >> a;
            A[i].push(a-1);
        }
        mem[A[i].front()].push_back(i);
    }

    REP(i,N){
        if(mem[i].size()==2){
            que.push(i);
        }
    }
    
    while(!que.empty){
        int now = que.front(); que.pop();

        for(auto p: mem[now]){
            A[p].pop();
            if(!A[p].empty()){
                mem[A[p].front()].push_back(p);
                if(mem[A[p].front()].size() == 2){
                    que.push(A[p].front());
                }
            }
        }
    }

    for(auto p: A){
        if(!p.empty()){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}