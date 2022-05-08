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


deque<int> getBinaryString(LL N){
    deque<int> S;
    if(N == 0){
        S.push_back(0);
        return S;
    }

    while(N != 0){
        if (N % 2 == 0){
            S.push_front(0);
        }else{
            S.push_front(1);
        }
        N = N / 2;
    }
    return S;
}


int main(){

    int N;
    LL X;
    cin >> N >> X;
    string S;
    cin >> S;

    deque<int> S_X = getBinaryString(X);
    REP(i, N){
        if(S[i] == 'U'){
            S_X.pop_back();
        }else if(S[i] == 'L'){
            S_X.push_back(0);
        }else if(S[i] == 'R'){
            S_X.push_back(1);
        }
    }

    LL x = 0;
    LL counter = 1;
    while(!S_X.empty()){
        LL val = S_X.back(); S_X.pop_back();
        x += val * counter;
        counter *= 2;
    }

    cout << x << endl;
    
    return 0;
}