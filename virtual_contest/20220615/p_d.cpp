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
    vector<LL> w(N);
    REP(i, N)cin >> w[i];


    reverse(ALL(w));

    vector<LL> costs;
    REP(i, N){
        if(costs.size() == 0){
            costs.push_back(w[i]);
            continue;
        }

        int idx = -1;
        int val = -1;
        REP(j, costs.size()){
            LL diff = w[i] - costs[j];
            if(diff >= 0){
                if(idx == -1){
                    idx = j;
                    val = abs(diff);
                    continue;
                }
                if(abs(val) > abs(diff)){
                    idx = j;
                    val = abs(diff);
                    continue;
                }
            }
        }
        
        if(idx == -1){
            costs.push_back(w[i]);
        }else{
            costs[idx] = w[i];
        }
    }

    LL ans = costs.size();
    // cout << ",,," << endl;
    // REP(i, ans){
    //     cout << costs[i] << endl;
    // }
    cout << ans << endl;
    return 0;
}