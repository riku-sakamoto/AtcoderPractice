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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


int K, N;
LL L;

bool checkPossible(vector<LL> A, LL target){
    int count = 0;
    LL pre = 0;
    for(int i=0; i<N; i++){
        if (A[i] - pre >= target && L - A[i] >= target){
            count += 1;
            pre = A[i];
        }
    }

    if(count >= K){
        return true;
    }else{
        return false;
    }

}


int main(){
    cin >> N >> L;
    cin >> K;
    vector<LL> A(N);
    REP(i, N) cin >> A[i];
    
    LL left = 1;
    LL right = L;

    while(true){

        LL mid = left + (right - left) / 2;
        if(checkPossible(A, mid) == false){
            right = mid;
        }else{
            left = mid;
        }

        // cout << left << "--" << right << endl;

        if(right - left <= 1){
            cout << left << endl;
            return 0;
        }

    }
}
