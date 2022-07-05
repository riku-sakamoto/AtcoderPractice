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
    vector<LL> A(N);
    vector<LL> sortA(N);
    REP(i, N){
        cin >> A[i];
        sortA[i] = A[i];
    }
    sort(ALL(sortA));


    vector<bool> checked(N, false);
    REP(i, N){
        if(checked[i] == true){
            continue;
        }

        vector<LL> B;
        for(int j=i; j<N; j+=K){
            B.push_back(A[j]);
            checked[j] = true;
        }
        // cout << i << ", " << B.size() << endl; 
        sort(ALL(B));
        for(int j=0; j<B.size(); j+=1){
            if(B[j] == sortA[i + j*K]){
                continue;
            }else{
                // cout << j << ", " << i << "," << i + j*K << endl;
                no();
                return 0;
            }
        }
        
    }

    yes();
    return 0;
}