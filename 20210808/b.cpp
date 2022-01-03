// #include <bits/stdc++.h>
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
    priority_queue<pair<LL, int>> que;
    LL val;
    REP(i,N){
        cin >> val;
        que.push(pair<LL, int>(val, i+1));
    }


    que.pop();
    pair<LL, int> ans = que.top();
    cout << ans.second << endl;
    return 0;

}