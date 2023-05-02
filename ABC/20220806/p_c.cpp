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

int N, M;

string get_char(int idx){
    return to_string(idx + 1);
}

void dfs(int idx, int rank, queue<string>& que, string tmp){
    if (rank == N){
        que.push(tmp);
    }else{
        FOR(i, idx, M - N + rank + 1){
            string c = get_char(i) + " ";
            dfs(i + 1, rank + 1, que, tmp + c);
        }
    }
}

int main(){
    cin >> N >> M;

    queue<string> que;

    // 初期位置
    dfs(0, 0, que, "");
    while(!que.empty()){
        string ans = que.front(); que.pop();
        out(ans);
    }
    return 0;
}