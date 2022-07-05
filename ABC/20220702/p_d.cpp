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
    LL X;
    cin >> N >> X;
    vector<LL> A(N);
    vector<LL> B(N);
    REP(i, N){
        cin >> A[i] >> B[i];
    }

    vector<LL> min_game_time(N);
    min_game_time[0] = B[0];
    FOR(i, 1, N){
        min_game_time[i] = min({min_game_time[i-1], B[i]});
    }

    LL INF = 1LL<<62;
    vector<LL> state(N, INF);
    if(X <= N){
        state[0] = A[0] + B[0] + (X - 1) * min_game_time[0];
        LL _min_time = A[0] + B[0];
        FOR(i, 1, X){
            _min_time += A[i] + B[i];
            state[i] = _min_time + (X - i - 1) * min_game_time[i];
        }

        sort(ALL(state));
        out(state[0]);
        return 0;
    }

    state[0] = A[0] + B[0] + (N - 1) * min_game_time[0];
    LL _min_time = A[0] + B[0];
    FOR(i, 1, N){
        _min_time += A[i] + B[i];
        state[i] = _min_time + (N - i - 1) * min_game_time[i];
    }

    REP(i, N){
        state[i] += (X - N) * min_game_time[i];
    }


    sort(ALL(state));
    out(state[0]);
    return 0;
}