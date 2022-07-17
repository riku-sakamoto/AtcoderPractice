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
    int N;
    cin >> N;
    vector<LL> A(N);
    map<LL, LL> numDict;
    REP(i, N){
        cin >> A[i];
        if(numDict.find(A[i]) == numDict.end()){
            numDict[A[i]] = 1LL;
        }else{
            numDict[A[i]] += 1LL;
        }
    }

    LL all = N * (N-1LL) * (N-2LL) / 6LL;

    for(auto item: numDict){
        if(item.second == 1)continue;

        LL k = item.second;
        
        all -= (N-k) * k * (k-1) / 2LL;
        if(item.second >= 3){
            all -= k * (k-1) * (k-2) / 6LL;
        }
    }

    cout << all << endl;

    return 0;
}