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
    int N, M;
    cin >> N >> M;
    vector<LL> balls(N, 1);
    vector<bool> reds(N, false);
    reds[0] = true;

    REP(i, M){
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        if(!reds[x]){
            balls[x] -= 1;
            balls[y] += 1;
            continue;
        }
        if(balls[x] == 1){
            reds[x] = false;
            reds[y] = true;
        }else{
            reds[y] = true;
        }
        balls[x] -= 1;
        balls[y] += 1;
        
    }

    int ans = 0;
    REP(i, N){
        if(reds[i]){
            ans += 1;
        }
    }

    out(ans);
    return 0;
}