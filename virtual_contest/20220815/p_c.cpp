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
    LL H,W;
    int N;
    cin >> H >> W >> N;
    vector<LL> Ai;
    vector<LL> Bi;
    set<LL> set_A;
    set<LL> set_B;
    REP(i, N){
        LL a, b;
        cin >> a >> b;
        Ai.push_back(a);
        Bi.push_back(b);
        set_A.insert(a);
        set_B.insert(b);
    }

    vector<LL> s_A(set_A.begin(), set_A.end());
    vector<LL> s_B(set_B.begin(), set_B.end());
    sort(ALL(s_A));
    sort(ALL(s_B));

    queue<pair<int, int>> que;
    REP(i, N){
        LL a = Ai[i];
        int a_idx = lower_bound(ALL(s_A), a) - s_A.begin();
        LL b = Bi[i];
        int b_idx = lower_bound(ALL(s_B), b) - s_B.begin();

        que.push({a_idx + 1, b_idx+ 1});

    }

    while(!que.empty()){
        auto k = que.front(); que.pop();
        cout << k.first << " " << k.second << endl;
    }
    return 0;
}