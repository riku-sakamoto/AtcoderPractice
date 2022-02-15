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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


int N;
LL L;
int K;

bool checkTarget(LL target, vector<LL>& A){
    LL pre = 0;
    LL count = 0;
    FOR(i, 0, N){
        if(A[i] - pre >= target && L - A[i] >= target){
            pre = A[i];
            count += 1;
        }
    }

    if(count < K){
        return false;
    }

    return true;
}


LL bisect(LL left, LL right, vector<LL>& A){
    if(right - left <= 1){
        return left;
    }

    LL target = left + (right - left)/2;
    bool isOk = checkTarget(target, A);
    if(isOk){
        left = target;
    }else{
        right = target;
    }
    return bisect(left, right, A);
}

int main(){
    cin >> N >> L;
    cin >> K;

    vector<LL> A(N);
    REP(i, N) cin >> A[i];

    LL left = 0;
    LL right = A[N-1];
    
    LL ans = bisect(left, right, A);    
    cout << ans << endl;

    return 0;
}