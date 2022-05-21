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
    int N, M;
    cin >> N >> M;
    vector<LL> A(N);
    vector<LL> B(N);
    vector<LL> C(M);
    vector<LL> D(M);
    REP(i, N)cin>>A[i];
    REP(i, N)cin>>B[i];
    REP(i, M)cin>>C[i];
    REP(i, M)cin>>D[i];

    vector<pair<LL, LL>> Choco(N);
    multiset<pair<LL, LL>> Box;
    
    REP(i, N){
        Choco[i] = {A[i], B[i]};
    }
    REP(i, M){
        Box.insert({C[i], D[i]});
    }

    sort(ALL(Choco));

    bool ans = true;
    REP(i, N){
        auto itr = lower_bound(ALL(Box), Choco[i]);
        if(itr == Box.end()){
            ans = false;
            break;
        }
        cout << (*itr).first << ", " << (*itr).second << endl;

        Box.erase((*itr));
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}