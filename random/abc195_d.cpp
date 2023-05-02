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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<LL, LL>> loads(N);
    vector<LL> boxes(M);
    REP(i, N){
        LL w, v;
        cin >> w >> v;
        loads[i] = {w, v};
    }
    REP(i, M){
        cin >> boxes[i];
    }
    sort(ALL(loads));


    queue<LL> que;
    REP(i, Q){
        int l, r;
        cin >> l >> r;

        set<int> usedIdx;
        LL val = 0LL;
        REP(i, M){
            if ((i >= l-1) && (i <= r-1)){
                continue;
            }

            LL tmp_max_val = -1LL;
            int tmp_max_idx = -1;
            REP(j, N){
                if(loads[j].first > boxes[i])continue;

                if(usedIdx.find(j) != usedIdx.end())continue;

                if (tmp_max_val <= loads[j].second){
                    tmp_max_idx = j;
                }
            }
            if(tmp_max_val == -1)continue;

            val += tmp_max_val;
        }
        que.push(val);
    }

    while(!que.empty()){
        LL ans = que.front(); que.pop();
        out(ans);
    }


    return 0;
}