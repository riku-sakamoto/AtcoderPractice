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


int main(){
    int N, Q;
    cin >> N;
    vector<LL> A(N);

    REP(i, N){
        cin >> A[i];
    }
    sort(ALL(A));

    cin >> Q;
    vector<LL> B(Q);
    REP(i, Q){
        cin >> B[i];
    }

    REP(i, Q){
        int index = lower_bound(ALL(A), B[i]) - A.begin();
        LL val = abs(A[index]-B[i]);

        if(index != 0){
            if(val > abs(A[index-1]-B[i])){
                val = abs(A[index-1]-B[i]);
            }
        }

        cout << val << endl;
    }
    return 0;

}