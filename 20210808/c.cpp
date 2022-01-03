#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(LL i=0;i<(n);i++)
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    LL H, W, N;
    cin >> H >> W >> N;

    vector<pair<LL, LL>> pairInputs(N);
    vector<LL> Rows(N, 0);
    vector<LL> Cols(N, 0);

    map<LL, LL> mp_r;
    map<LL, LL> mp_c;

    REP(i,N){
        LL ai, bi;
        cin >> ai >> bi;
        pairInputs[i] = pair<LL, LL>(ai, bi);

        // existRows[ai-1] += 1;
        // existCols[bi-1] += 1;

        Rows[i] = ai;
        Cols[i] = bi;
    }

    sort(Rows.begin(), Rows.end());
    sort(Cols.begin(), Cols.end());

    REP(i, N){
        LL ai = Rows[i];
        if(mp_r.count(ai) == 0){
            mp_r[ai] = i;
        }
    }

    REP(i, N){
        LL bi = Cols[i];
        if(mp_c.count(bi) == 0){
            mp_c[bi] = i;
        }
    }
    
    REP(i, N){
        LL ai = pairInputs[i].first;
        LL bi = pairInputs[i].second;

        LL offsetA = ai - 1 - mp_r[ai];
        LL offsetB = bi - 1 - mp_c[bi];

        // cout << indexRow << "," << indexCol << endl;
        cout << ai - offsetA << " " << bi - offsetB << endl;
    }

   
    return 0;
}