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


int getNumber(vector<LL> A, int index){ 
    LL val = A[index];
    int num = 1;
    FOR(i,index+1,A.size()){
        if(A[i]==val){
            num+= 1;
        }else{
            break;
        }
    }
    return num;
}

LL getSum(LL val, LL count){
    LL ans = (val + (val - count + 1)) * count / 2;
    return ans;
}

int main(){
    int N;
    LL K;
    cin >> N >> K;
    vector<LL> A(N);
    REP(i,N)cin>>A[i];

    sort(ALL(A), greater<LL>())
    LL times = 0;
    int index = 0;
    LL ans = 0;
    while(times < K){
        LL maxp = A[index];
        int nums = getNumber(A, index);

        LL nextp = 0;
        if(index + nums < N){
            nextp = A[index + nums];
        }

        LL count()
    }    
}