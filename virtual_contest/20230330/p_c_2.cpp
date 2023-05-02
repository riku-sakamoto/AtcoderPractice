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


pair<int, int> find_cycle(vector<vector<int>>& states, vector<int>& state){
    int i = 0;
    int n = states.size();
    for(auto _state: states){
        if(_state == state){
            int cycle = n - i;
            return {cycle, i};
        }
        i++;
    }
    return {-1, -1};
}

LL getPow(LL val, LL n, LL p){
    // バイナリ法
    LL ans = 1;
    while(n > 0){
        ans = ans % p;
        if((n & 1) == 1){
            ans = (ans * (val%p)) % p;
        }
        val = ((val%p) * (val%p))%p;
        n = n >> 1;
    }
    return ans%p;
}


int main(){
    cin >> S;

    int n = S.size();
    vector<int> state(n, 1);

    vector<vector<int>> states;
    states.push_back(state);

    pair<int, int> finds;
    while(true){
        auto next_state = calc_next_state(state);

        finds = find_cycle(states, next_state);

        if (finds.first != -1){
            break;
        }

        states.push_back(next_state);
        state = next_state;
    }

    // cout << finds.first << ", " << finds.second << endl;
    LL p = (LL)(finds.first);
    LL pow = getPow(10LL, 100LL, p);

    LL tmp = pow - (LL)finds.second % p;
    if(tmp < 0) {
        tmp += p;
    }
    LL k = tmp % p;
    // cout << "k: " << k << endl;

    state = states[k + finds.second];
    REP(i, n){
        cout << state[i] << " ";
    }
    cout << endl;

    return 0;
}