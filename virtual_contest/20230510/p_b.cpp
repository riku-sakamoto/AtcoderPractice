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
    LL W;
    cin >> N >> W;
    vector<LL> A(N);
    REP(i, N){
        cin >> A[i];
    }

    set<LL> values;
    REP(i, N){
        LL tmp = A[i];
        if (tmp <= W) {
          values.insert(tmp);
        }
        FOR(j, i + 1, N){
            tmp = A[i] + A[j];
            if (tmp <= W) {
                values.insert(tmp);
            }
            FOR(k, j + 1, N){
                tmp = A[i] + A[j] + A[k];
                if(tmp <= W){
                    values.insert(tmp);
                }
            }
        }
    }

    int ans = values.size();
    out(ans);
    return 0;
}