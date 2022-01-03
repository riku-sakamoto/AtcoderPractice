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
    vector<LL> Ai(N, 0);
    REP(i, N){
        cin >> Ai[i];
    }

    vector<LL> Li(Q, 0);
    vector<LL> Ri(Q, 0);
    vector<LL> Vi(Q, 0);
    REP(i, Q){
        cin >> Li[i] >> Ri[i] >> Vi[i];
    }

    vector<LL> Diffs(N-1, 0);
    LL sum_diff = 0;
    REP(i, N-1){
        Diffs[i] = Ai[i+1] - Ai[i];
        sum_diff += abs(Diffs[i]);
    }

    queue<LL> ans;

    REP(i, Q){
        LL l = Li[i];
        LL r = Ri[i];
        LL v = Vi[i];

        LL diff = 0;
        if(l != 1){
            diff += abs(Diffs[l-2] + v) - abs(Diffs[l-2]);
            Diffs[l-2] += v;
        }

        if(r != N){
            diff += abs(Diffs[r-1] - v) - abs(Diffs[r-1]);
            Diffs[r-1] -= v;
        }

        // REP(i, N-1){
        //     cout << Diffs[i] << " ";
        // }
        // cout << endl;

        sum_diff += diff;
        ans.push(sum_diff);
    }

    while (!ans.empty())
    {
        LL v = ans.front();ans.pop();
        cout << v << endl;
    }
    
    return 0;
}