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

    vector<pair<LL, LL>> coords(N);
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    priority_queue<double> que;

    REP(i, N){
        FOR(j, i+1, N){
            pair<LL, LL> coord1 = coords[i];
            pair<LL, LL> coord2 = coords[j];

            double dist = (coord1.first - coord2.first) * (coord1.first - coord2.first) + (coord1.second - coord2.second) * (coord1.second - coord2.second);
            dist = sqrt(dist);
            que.push(dist);
        }
    }

    double ans = que.top();

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}