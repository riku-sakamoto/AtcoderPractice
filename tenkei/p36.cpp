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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<LL> x(N);
    vector<LL> y(N);

    REP(i, N){
        cin >> x[i] >> y[i];
    }

    vector<int> q(Q);
    REP(i, Q){
        cin >> q[i];
    }

    vector<LL> X(N);
    vector<LL> Y(N);

    REP(i, N){
        X[i] = x[i] + y[i];
        Y[i] = x[i] - y[i];
    }

    LL max_X = *max_element(ALL(X));
    LL min_X = *min_element(ALL(X));
    LL max_Y = *max_element(ALL(Y));
    LL min_Y = *min_element(ALL(Y));

    
    REP(i, Q){
        int index = q[i] - 1;
        cout << max({abs(min_X - X[index]), abs(max_X - X[index]), abs(min_Y - Y[index]), abs(max_Y - Y[index])}) << endl;
    }
    return 0;
}