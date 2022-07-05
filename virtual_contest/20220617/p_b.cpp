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
    string S;
    cin >> S;
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<char> ans;
    int N = S.size();
    REP(i, N){
        if(i==A || i==B || i==C || i==D){
            ans.push_back('"');
        }
        ans.push_back(S[i]);        
    }
    if(D == S.size()){
        ans.push_back('"');
    }

    REP(i, ans.size()){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}