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
    int N;
    LL K;
    cin >> N >> K;
    vector<LL> A(N);
    vector<LL> B(N);
    REP(i, N){
        cin >> A[i];
    }
    REP(i, N){
        cin >> B[i];
    }

    
    queue<LL> que;
    bool ans = true;
    que.push(A[0]);
    que.push(B[0]);
    FOR(i, 1, N){
        if(que.empty()){
            ans = false;
            break;
        }
        queue<LL> next_que;
        set<LL> next_val;
        while(!que.empty()){
            LL val = que.front(); que.pop();
            if(abs(val-A[i]) <= K){
                next_val.insert(A[i]);
            }
            if(abs(val-B[i]) <= K){
                next_val.insert(B[i]);
            }
        }
        for(auto x: next_val){
            next_que.push(x);
        }
        que = next_que;
    }

    if(que.empty()){
        ans = false;
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}