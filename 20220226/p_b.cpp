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
    vector<LL> B(M);
    map<LL, int> Acount;
    REP(i, N){
        cin >> A[i];
        if(Acount.find(A[i]) == Acount.end()){
            Acount[A[i]] = 1;
        }else{
            Acount[A[i]] += 1;
        }
    }
    REP(i, M){
        cin >> B[i];
    }

    bool ans = true;
    REP(i, M){
        LL target = B[i];
        if(Acount.find(target) == Acount.end()){
            ans = false;
            break;
        }
        if(Acount[target] == 0){
            ans = false;
            break;
        }
        Acount[target] -= 1;
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}