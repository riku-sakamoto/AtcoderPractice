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
    LL H, W, N;
    cin >> H >> W >> N;

    vector<pair<LL, LL>> pairInputs(N);
    vector<LL> Rows(N, 0);
    vector<LL> Cols(N, 0);

    REP(i,N){
        LL ai, bi;
        cin >> ai >> bi;
        pairInputs[i] = pair<LL, LL>(ai, bi);
        Rows[i] = ai;
        Cols[i] = bi;
    }

    sort(ALL(Cols));
    Cols.erase(unique(ALL(Cols)), Cols.end());

    // 重複の削除
    // 1.ソート
    sort(ALL(Rows));
    // 2.uniqueで隣接する重複削除 => vectorの長さを変更しないため，末尾にゴミが残る
    // 3.uniqueはごみの手前のポインタを返すので，そこから最後までeraseで削除
    Rows.erase(unique(ALL(Rows)), Rows.end());

    REP(i,N){
        LL a = pairInputs[i].first;
        LL b = pairInputs[i].second;
        // インデックスの検索
        // ソート済み範囲に対して、任意の値を二分探索で見つける
        LL i_r = lower_bound(ALL(Rows), a) - Rows.begin();
        LL i_c = lower_bound(ALL(Cols), b) - Cols.begin();

        cout << 1 + i_r << " " << i_c + 1 << endl;
    }



    return 0;

}