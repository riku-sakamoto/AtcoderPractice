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


bool checkValidCond(vector<tuple<int, int, int , LL>>& conds, int val, int nbit, int Q){
    REP(i, Q){
        int x = get<0>(conds[i]) - 1;
        int y = get<1>(conds[i]) - 1;
        int z = get<2>(conds[i]) - 1;
        LL target = get<3>(conds[i]);

        int target_bit = ((target & (1LL<<nbit)) != 0);
        int val_x = ((val&(1<<x)) != 0);
        int val_y = ((val&(1<<y)) != 0);
        int val_z = ((val&(1<<z)) != 0);

        if((val_x | val_y | val_z) == target_bit){
            continue;
        }else{
            return false;
        }
    }

    return true;
}

int main(){
    LL LARGE_VALUE = 1000000007;
    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int , LL>> conds;
    REP(i, Q){
        int x, y, z;
        LL w;
        cin >> x >> y >> z >> w;
        conds.push_back({x, y, z, w});
    }


    // ビットごとに判定する
    int val = 1 << N;
    vector<LL> counts;
    REP(i, 60){
        LL tmp_count = 0;
        // iビット目のペアを全探索する
        // valのｎビット目が数列Aの要素nのiビット目に対応
        REP(k, val){
            bool isValid = checkValidCond(conds, k, i, Q);
            if(isValid){
                tmp_count = (tmp_count + 1) % LARGE_VALUE;
            }
        }
        // cout << i << ", " << tmp_count << endl;
        counts.push_back(tmp_count);
    }

    LL ans = 1;
    for(auto val: counts){
        ans = (ans * val) % LARGE_VALUE;
    }

    cout << ans << endl;
    return 0;
}