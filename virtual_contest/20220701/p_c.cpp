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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N)cin >> A[i];

    vector<bool> searched(N, false);
    REP(i, N){
        if(searched[i] == true){
            continue;
        }
        vector<int> B;
        for(int j=i; j<N; j+=K){
            B.push_back(A[j]);
            searched[j] = true;
        }
        sort(ALL(B));
        int k =0;
        for(int j=i; j<N; j+=K){
            A[j] = B[k];
            ++k;
        }
    }
    // REP(i, N){
    //     cout << A[i] << ", ";
    // }
    // cout << endl;


    bool ans = true;
    REP(i, N-1){
        if(A[i] > A[i+1]){
            ans = false;
            break;
        }
    }

    if(ans){
        yes();
    }else{
        no();
    }
    return 0;
}