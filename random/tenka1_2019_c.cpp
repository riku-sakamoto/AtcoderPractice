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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    int N;
    string S;
    cin >> N >> S;

    vector<int> sums_black(N+1, 0);
    REP(i, N){
        if (S[i] == '#'){
            sums_black[i + 1] = sums_black[i] + 1;
        }else{
            sums_black[i + 1] = sums_black[i];
        }
    }
    
    vector<int> sums_white(N+1, 0);

    REPREV(i, N+1){
        if (i == 0)break;
        if(S[i] == '.'){
            sums_white[i - 1] = sums_white[i] + 1;
        }else{
            sums_white[i - 1] = sums_white[i];
        }
    }


    int ans = N;
    REP(i, N+1){
        int val = sums_black[i] + sums_white[i];
        chmin(ans, val);
    }
    out(ans);
    return 0;
}