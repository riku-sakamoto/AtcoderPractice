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


int main(){
    int N;
    LL L, R;
    cin >> N >> L >> R;
    vector<LL> A(N);
    REP(i, N)cin>>A[i];

    LL sumA = 0LL;
    REP(i, N){
        sumA += A[i];
    }
    vector<LL> sumsA_over_i(N);
    LL tmp_sum = sumA;
    REP(i, N){
        tmp_sum -= A[i];
        sumsA_over_i[i] = tmp_sum;
    }

    // x
    LL min_sum = sumA;
    int x_idx = -1;
    REP(i, N){
        LL L_sum = L * (i + 1) * 1LL;
        LL other_sum = sumsA_over_i[i];
        LL _tmp_sum = L_sum + other_sum;
        if (_tmp_sum < min_sum){
            min_sum = _tmp_sum;
            x_idx = i;
        }
    }

    // iより下の和
    vector<LL> sumsA_under_i(N);
    tmp_sum = 0LL;
    REP(i, N){
        sumsA_under_i[i] = tmp_sum;
        if (i <= x_idx){
            tmp_sum += L;
        }else{
            tmp_sum += A[i];
        }
    }

    // min_sum
    // y
    int y_idx = -1;
    REP(i, N){
        LL R_sum = R * (i + 1LL) * 1LL;
        LL other_sum = sumsA_under_i[N - 1 - i];
        LL _tmp_sum = R_sum + other_sum;
        if (_tmp_sum < min_sum){
            min_sum = _tmp_sum;
            y_idx = i;
        }
    }

    // out(x_idx);
    // out(y_idx);
    out(min_sum);


    return 0;
}