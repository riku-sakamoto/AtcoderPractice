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


string S;

vector<int> calc_next_state(vector<int> humans){
    int n = S.size();
    vector<int> new_state(n, 0);

    REP(i, S.size()){
        char c = S[i];
        int v = humans[i];
        if (v == 0){
            continue;
        }

        if (c == 'R'){
            new_state[i + 1] += v;
        }

        if(c == 'L'){
            new_state[i - 1] += v;
        }

    }
    return new_state;

}


int main(){
    cin >> S;

    int n = S.size();
    vector<int> state(n, 1);

    pair<int, int> finds;
    REP(i, 100000){
        auto next_state = calc_next_state(state);
        state = next_state;
    }

    REP(i, n){
        cout << state[i] << " ";
    }
    cout << endl;

    return 0;
}