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

LL goUp(LL x){
    return x / 2;
}

LL goLeft(LL x){
    return 2 * x;
}

LL goRight(LL x){
    return 2 * x + 1;
}

int main(){
    int N;
    LL X;
    string S;
    cin >> N >> X >> S;

    bool iseven = (X % 2 == 0);
    deque<char> que;
    que.push_back(S[0]);
    int i = 1;
    while(i < N){
        // U, L, R 
        U, L, R;
    }

    while(!que.empty()){
        char c = que.front(); que.pop();

        if(c == 'U'){
            X = goUp(X);
            continue;
        }

        if(c == 'L'){
            X = goLeft(X);
            continue;
        }

        if(c == 'R'){
            X = goRight(X);
            continue;
        }
    }
    cout << X << endl;
    return 0;
}