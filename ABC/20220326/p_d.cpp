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
    vector<LL> A(N+1);
    REP(i, N+1){
        cin >> A[i];
    }
    vector<LL> C(N+M+1);
    REP(i, N+M+1){
        cin >> C[i];
    }

    reverse(ALL(A));
    reverse(ALL(C));

    vector<LL> B;
    vector<LL> tmp(N+M+1, 0);
    REP(i, M+1){
        LL Bi = (C[i] - tmp[i]) / A[0];
        B.push_back(Bi);
        // cout << "B" << i << ", " <<  Bi << endl;

        FOR(j, 0, N+1){
            tmp[j+i] += A[j] * B[i];
            // cout << j << ", " << tmp[j] << endl;
        }
    }

    reverse(ALL(B));
    REP(i, M+1){
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}