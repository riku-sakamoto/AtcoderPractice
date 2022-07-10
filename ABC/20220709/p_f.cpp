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
    vector<int> d(N);
    REP(i, N)cin>>d[i];

    vector<tuple<int, int, LL>> edges;
    int us = 0;
    int vs = 0;
    LL wmax = 0;
    REP(i, N-1){
        int u, v;
        LL w;
        cin >> u >> v >> w;
        if(w >= wmax){
            us = u-1;
            vs = v - 1;
            wmax = w;
        }
        edges.push_back({u-1, v-1, w});
    }

    auto comp = [](tuple<int, int, LL> l, tuple<int, int, LL> r){return get<2>(l)>get<2>(r);};
    priority_queue<tuple<int, int, LL>, vector<tuple<int, int, LL>>, decltype(comp)> que(comp);

    while(true){
        
    }

    return 0;
}