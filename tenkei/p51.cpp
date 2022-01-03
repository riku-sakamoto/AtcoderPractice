#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
    int N, K;
    LL P;
    cin >> N >> K >> P;

    vector<LL> A(N);
    REP(i, N)cin >> A[i];



    int mid = N / 2; 
    vector<vector<LL>> vec1(mid+1);
    // 最大mid個の１を発生させる
    REP(i, 1 << mid){
        LL cnt1 = 0;
        LL cnt2 = 0;

        // 各桁について１が出現しているか調べる
        REP(j, mid){
            if((i & (1 << j)) != 0){
                cnt1 += A[j];
                cnt2 += 1;
            }
        }

        vec1[cnt2].push_back(cnt1);
    }

    vector<vector<LL>> vec2(N-mid+1);
    // 最大mid個の１を発生させる
    REP(i, 1 << N-mid){
        LL cnt1 = 0;
        LL cnt2 = 0;

        // 各桁について１が出現しているか調べる
        REP(j, N-mid){
            if((i & (1 << j)) != 0){
                cnt1 += A[mid+j];
                cnt2 += 1;
            }
        }

        vec2[cnt2].push_back(cnt1);
    }

    REP(i, vec1.size()){
        sort(ALL(vec1[i]));
    }
    REP(i, vec2.size()){
        sort(ALL(vec2[i]));
    }
    // REP(i, vec1.size()){
    //     REP(j, vec1[i].size()){
    //         cout << "vec1: "<< i << ": " << vec1[i][j] << endl;
    //     }
    // }
    // REP(i, vec2.size()){
    //     REP(j, vec2[i].size()){
    //         cout << "vec2: "<< i << ": " << vec2[i][j] << endl;
    //     }
    // }

    LL ans = 0;

    REP(i, vec1.size()){
        // group1からi個選ぶ
        if(i > K){ break; }
        for(LL p: vec1[i]){
            // i個選んだ時の価格
            if(K-i >= vec2.size()){break;}
            int num = lower_bound(ALL(vec2[K-i]), P-p+1) - vec2[K-i].begin();
            ans += (LL)num;
        }
    }

    cout << ans << endl;
    return 0;
}