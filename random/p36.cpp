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


int main(){
    int N, Q;
    cin >> N >> Q;

    vector<pair<LL, LL>> Point;
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        Point.push_back({x, y});
    }

    vector<LL> X;
    vector<LL> Y;
    REP(i, N){
        LL x = Point[i].first;
        LL y = Point[i].second;
        X.push_back(x+y);
        Y.push_back(x-y);
    }
    sort(ALL(X));
    sort(ALL(Y));

    queue<LL> ans;
    REP(i, Q){
        int q;
        cin >> q;
        LL ansVal = 0;
        LL x = Point[q-1].first;
        LL y = Point[q-1].second;
        LL nx = x + y;
        LL ny = x - y;

        chmax(ansVal, abs(X[0] - nx));
        chmax(ansVal, abs(X[N-1] - nx));
        chmax(ansVal, abs(Y[0] - ny));
        chmax(ansVal, abs(Y[N-1] - ny));
        ans.push(ansVal);
    }

    while(!ans.empty()){
        LL val = ans.front(); ans.pop();
        cout << val << endl;
    }

    return 0;
}