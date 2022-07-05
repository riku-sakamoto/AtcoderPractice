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
    vector<string> blues(N);
    REP(i, N)cin>> blues[i];

    int M;
    cin >> M;
    vector<string> reds(M);
    REP(i, M)cin>> reds[i];

    priority_queue<int> que;
    REP(i, N){
        string target = blues[i];
        int point = 0;
        REP(j, N){
            if(blues[j] == target){
                ++point;
            }
        }

        REP(j, M){
            if(reds[j] == target){
                --point;
            }
        }

        que.push(point);

    }

    int ans = que.top();
    if(ans < 0){
        out(0);
    }else{
        out(ans);
    }
    return 0;
}