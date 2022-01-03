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
    int N;
    cin >> N;
    vector<int> C(N);
    vector<int> P(N);

    REP(i,N){
        cin >> C[i] >> P[i];
    }

    int Q;
    cin >> Q;
    vector<int> L(Q);
    vector<int> R(Q);

    REP(i,Q){
        cin >> L[i] >> R[i];
    }

    vector<int> SumScores1(N+1, 0);
    vector<int> SumScores2(N+1, 0);
    int score1 = 0;
    int score2 = 0;

    REP(i, N){
        if(C[i]==1){ score1 += P[i]; }
        if(C[i]==2){ score2 += P[i]; }
        
        SumScores1[i+1] = score1;
        SumScores2[i+1] = score2;
    }

    
    REP(i,Q){ 
        int l = L[i];
        int r = R[i];
        int ans1 = SumScores1[r] - SumScores1[l-1];
        int ans2 = SumScores2[r] - SumScores2[l-1];

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;

}