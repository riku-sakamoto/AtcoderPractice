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
    vector<vector<int>> Ans;

    REP(i, N){
        vector<int> B;
        REP(j, i+1){
            if(j==0 || j==i){
                B.push_back(1);
            }else{
                B.push_back(Ans[i-1][j-1] + Ans[i-1][j]);
            }
        }
        Ans.push_back(B);
    }

    REP(i, N){
        REP(j, i+1){
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}