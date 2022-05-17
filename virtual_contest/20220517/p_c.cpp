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
    cin >> N;
    vector<int> A(N, 0);
    REP(i, N){
        cin >> A[i];
    }
    map<int, int> valueMap;
    REP(i, N){
        if(valueMap.find(A[i]) == valueMap.end()){
            valueMap[A[i]] = 1;    
        }else{
            valueMap[A[i]] += 1;
        }
    }
    LL tmp_sum = 0;
    REP(i, N){
        tmp_sum += A[i];
    }
    
    queue<LL> que;
    int Q;
    cin >> Q;
    REP(i, Q){
        int b, c;
        cin >> b >> c;

        if(valueMap.find(b) == valueMap.end()){
            que.push(tmp_sum);
            continue;
        }

        tmp_sum += valueMap[b] * (c - b);
        valueMap[c] += valueMap[b];
        valueMap[b] = 0;

        que.push(tmp_sum);
        
    }

    while(!que.empty()){
        LL val = que.front();
        que.pop();

        cout << val << endl;
    }

    return 0;
}