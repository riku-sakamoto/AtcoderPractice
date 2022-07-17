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
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    int _tmp_t2 = 0;
    vector<int> pos(2 * N);
    REP(i, 2 * N){
        pos[i] = i;
    }
    REP(i, Q){
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1){
            int pos_a = ((a - 1) + _tmp_t2) % (2*N);
            int pos_b = ((b - 1) + _tmp_t2) % (2*N);
            int _i_a = pos[pos_a];
            int _i_b = pos[pos_b];
            pos[pos_a] = _i_b;
            pos[pos_b] = _i_a;
        }

        if(t == 2){
            _tmp_t2 += N;
            _tmp_t2 = _tmp_t2 % (2 * N);
        }
    }


    // REP(i, 2*N){
    //     cout << pos[i] << ", ";
    // }
    // cout << endl;
    REP(i, 2*N){
        int idx = (i + _tmp_t2) % (2 * N);
        int _idx = pos[idx];
        cout << S[_idx];
    }
    cout << endl;

    return 0;
}