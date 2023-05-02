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


LL pow(LL x, int t){
    LL ans = 1LL;
    while(t > 0){
        ans *= x;
        --t;
    }
    return ans;
}

LL calcPoint(string S){
    vector<int> count;
    REP(i, 10){
        count.push_back(0);
    }
    REP(i, 5){
        if(S[i] == '#')continue;
        int k = S[i] - '0';
        count[k-1] += 1;
    }

    LL point = 0;
    FOR(i, 1, 10){
        point += 1LL * i * pow(10LL, count[i-1]);
    }
    return point;
}

vector<int> counts(string S){
    vector<int> count;
    REP(i, 10){
        count.push_back(0);
    }
    REP(i, 5){
        if(S[i] == '#')continue;
        int k = S[i] - '0';
        count[k-1] += 1;
    }
    return count;
}

int main(){
    LL K;
    string S, T;
    cin >> K >> S >> T;

    // LL p_S = calcPoint(S);
    // LL p_T = calcPoint(T);
    // cout << p_S << ", " << p_T << endl;

    vector<int> countS = counts(S);
    vector<int> countT = counts(T);

    vector<LL> count_master(10, K);
    REP(i, 10){
        count_master[i] = K - countS[i] - countT[i];
    }

    double n_pairs = 0;
    FOR(i, 1, 10){
        if(count_master[i-1] == 0)continue;

        S[4] = (i + '0');
        LL tmp_pS = calcPoint(S);

        FOR(j, 1, 10){
            if(count_master[j-1] == 0) continue;

            if( i == j ){
                if(count_master[i-1] <= 1) continue;
            }

            T[4] = (j + '0');
            LL tmp_pT = calcPoint(T);

            if(tmp_pS > tmp_pT){
                if (i == j){
                    n_pairs += count_master[i-1] * (count_master[j-1] - 1);
                }else{
                    n_pairs += count_master[i-1] * count_master[j-1];
                }
            }
        }
    }
    // out(n_pairs);

    double all = (9 * K - 8) * (9 * K - 8 - 1);
    double p = n_pairs / (double)all;
    cout << fixed << setprecision(15) << p << endl;

    return 0;
}