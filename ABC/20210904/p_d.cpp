#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <list>
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
    LL L;
    int Q;
    cin >> L >> Q;
    set<LL> answers;
    answers.insert(L);
    answers.insert(0); 

    queue<LL> que;
    REP(i, Q){
        int c;
        LL x;
        cin >> c >> x;

        if(c == 1){
            answers.insert(x);
        }else{
            auto it = answers.lower_bound(x);
            LL l1 = *it;
            LL l2 = *prev(it);
            // cout << "l1:" << l1 << ", l2:" << l2 << endl;
            que.push(l1-l2);
        }
    }

    while(!que.empty()){
        LL x = que.front(); que.pop();

        cout << x << endl;
    }
    return 0;

}