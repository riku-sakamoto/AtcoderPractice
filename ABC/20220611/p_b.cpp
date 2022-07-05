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
    int N, K;
    cin >> N >> K;
    vector<LL> A(K);
    REP(i, K)cin >> A[i];

    vector<pair<LL, LL>> coords(N);
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    vector<double> min_dists(K, 0);
    REP(i, N){
        pair<LL, LL> coord = coords[i];
        int min_idx = 0;
        double min_dist = 10000000;
        REP(j, K){
            int target_idx = A[j] - 1;
            pair<LL, LL> target_coord = coords[target_idx];

            // cout << target_idx << ',' << i << endl;
            // cout << (target_coord.first - coord.first)*(target_coord.first - coord.first) + (target_coord.second - coord.second)*(target_coord.second - coord.second) << endl;
            LL val = (target_coord.first - coord.first)*(target_coord.first - coord.first) + (target_coord.second - coord.second)*(target_coord.second - coord.second);
            // cout << val << endl;

            double dist = sqrt((target_coord.first - coord.first)*(target_coord.first - coord.first) + (target_coord.second - coord.second)*(target_coord.second - coord.second));

            if(min_dist > dist){
                min_idx = j;
                min_dist = dist;
            }
        }
        // cout << min_idx << ", " << min_dist << endl;

        chmax(min_dists[min_idx], min_dist);
    }


    sort(ALL(min_dists));

    cout << fixed << setprecision(20) << min_dists[K-1] << endl;

    return 0;
}