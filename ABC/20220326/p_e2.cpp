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

    vector<tuple<LL, LL, int>> Choco_Box;
    
    REP(i, N){
        // Choco
        Choco_Box.push_back({A[i], B[i], 0});
    }
    REP(i, M){
        // Box
        Choco_Box.push_back({C[i], D[i], 1});
    }

    sort(ALL(Choco_Box));
    reverse(ALL(Choco_Box));

    multiset<LL> S;
    bool ans = true;

    REP(i, N+M){
        auto item = Choco_Box[i];
        if(get<2>(item) == 1){
            S.insert(get<1>(item));
            continue;
        }

        LL yoko = get<1>(item);
        auto itr = S.lower_bound(yoko);
        if(itr == S.end()){
            ans = false;
            break;
        }else{
            S.erase(itr);
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}