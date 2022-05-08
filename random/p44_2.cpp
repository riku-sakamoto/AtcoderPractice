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

int getIndex(int num, int N){
    while(num < 0){
        num += N;
    }

    return num % N;
}


int main(){
    int N, Q;
    cin >> N >> Q;
    vector<LL> A(N, 0);
    REP(i, N){
        cin >> A[i];
    }

    int shift = 0;
    queue<LL> ans;
    REP(i, Q){
        int T, x, y;
        cin >> T >> x >> y;
        if(T == 1){
            int idx = getIndex(x - 1 - shift, N);
            int idy = getIndex(y - 1 - shift, N);
            swap(A[idx], A[idy]);
        }else if(T == 2){
            shift += 1;
        }else{
            int idx = getIndex(x - 1 - shift, N);
            ans.push(A[idx]);
        }
    }

    while(!ans.empty()){
        LL val = ans.front(); ans.pop();
        cout << val << endl;
    }
    
    return 0;
}