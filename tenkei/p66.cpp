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

double calcTransposeEx(int l1, int r1, int l2, int r2){
    double all = (r1 - l1 + 1) * (r2 - l2 + 1);

    double count = 0;
    FOR(v1, l1, r1+1){
        FOR(v2, l2, r2+1){
            if(v1 > v2){
                count += 1;
            }
        }
    }
    return count / all;
}


int main(){
    int N;
    cin >> N;
    vector<int> Li(N);
    vector<int> Ri(N);
    REP(i, N){
        cin >> Li[i] >> Ri[i];
    }

    double ans = 0;
    REP(i, N){
        int l1 = Li[i];
        int r1 = Ri[i];
        FOR(j, i+1, N){
            int l2 = Li[j];
            int r2 = Ri[j];
            ans += calcTransposeEx(l1, r1, l2, r2);
        }
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}