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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}


LL getPow(LL val, int n){
    LL ans = 1;
    REP(i, n){
        ans *= val;
    }
    return ans;
}


LL calcPoint(int val, string S){
    map<int, int> counts;
    FOR(i, 1, 10){
        counts[i] = 0;
    }
    REP(i, S.size() - 1){
        int k = S[i] - '0';
        counts[k] += 1;
    }
    counts[val] += 1;

    LL ans = 0LL;
    for(auto v: counts){
        ans += (v.first * getPow(10LL, v.second));
    }

    return ans;

}

int main(){
    int K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    map<int, int> counts;
    FOR(i, 1, 10){
        counts[i] = K;
    }
    REP(i, S.size() - 1){
        int a = S[i] - '0';
        counts[a] -= 1;
        int b = T[i] - '0';
        counts[b] -= 1;
    }

    LL ans = 0LL;
    FOR(i, 1, 10){
        if(counts[i] - 1 < 0){
            continue;
        }
        FOR(j, 1, 10){
            if(counts[j] - 1 < 0){
                continue;
            }
            if(i == j){
                if(counts[i] - 2 < 0){
                    continue;
                }
            }
            
            LL s_point = calcPoint(i, S);
            LL t_point = calcPoint(j, T);

            if(s_point <= t_point){
                continue;
            }
            if(i == j){
                ans += ((LL)counts[i] * (LL)(counts[j] - 1));
            }else{
                ans += ((LL)counts[i] * (LL)counts[j]);
            }

        }
    }

    LL all = (LL)(9*K - 8) * (LL)(9*K - 9);
    double ans_p = (double)ans / (double)(all);

    // cout << all << endl;
    // cout << ans << endl;
    cout << setprecision(10) << ans_p << endl;
    return 0;
}