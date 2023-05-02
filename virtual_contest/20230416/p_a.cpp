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
    int A, B;
    cin >> A >> B;

    vector<LL> que;
    LL total = 0LL;
    if (B > A){
        REP(i, A-1){
            que.push_back((LL)(i + 1));
            total += (i + 1);
        }

        REP(i, B){
            que.push_back((LL)(- (i + 1)));
            total -= (i + 1);
        }

        que.push_back(-total);
    } else {
        REP(i, A){
            que.push_back((LL)(i + 1));
            total += (i + 1);
        }

        REP(i, B - 1){
            que.push_back((LL)(- (i + 1)));
            total -= (i + 1);
        }

        que.push_back(-total);
    }
    
    for(auto v: que){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}