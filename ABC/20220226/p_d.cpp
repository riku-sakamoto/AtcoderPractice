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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int Q;
    cin >> Q;
    priority_queue<LL> que;
    priority_queue<LL, vector<LL>, greater<LL>> rque;
    queue<LL> ans;    
    REP(i, Q){
        int j, k;
        LL x;
        cin >> j;
        if(j == 1){
            cin >> x;
            que.push(x);
            rque.push(x);
        }
        if(j== 2){
            cin >> x >> k;
        }
    }
    return 0;
}