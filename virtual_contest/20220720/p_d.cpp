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
    int N; LL K;
    cin >> N >> K;
    vector<int> P(N);
    vector<LL> C(N);
    REP(i, N){
        int p;
        cin >> p;
        P[i] = p - 1;
    }
    REP(i, N)cin >> C[i];

    vector<int> Group(N, -1);
    vector<int> Cycle;
    vector<LL> CycleSums;
    int k = 0;
    REP(i, N){
        if(Group[i] != -1) continue;
        int v = P[i];
        int count = 0;
        LL cycle_sum = 0;
        while(true){
            Group[v] = k;
            ++count;
            cycle_sum += C[v];
            v = P[v];
            if (v == i) break;
        }
        ++k;
        Cycle.push_back(count);
        CycleSums.push_back(cycle_sum);
    }

    priority_queue<LL> que;
    REP(i, N){
        int group_id = Group[i];
        int cycle_count = Cycle[group_id];
        LL cycle_sum = CycleSums[group_id];
        
        int v = P[i];
        LL cnt = 0LL;
        LL point = 0LL;

        while(true){
            ++cnt;
            point += C[v];

            if (cnt > K) break;
            if(cycle_sum >= 0){
                LL cycles = (K - cnt) / (1LL * cycle_count);
                point += max({cycles, 0LL}) * cycle_sum;
            }
            que.push(point);

            v = P[v];
            if (v == i) break;

        }
    }

    LL ans = que.top();
    out(ans);

    return 0;
}