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


LL counting(string& S, vector<bool>& changed, bool last_changed){
    LL count = 0LL;
    REP(i, S.size()){
        int pre_i = i - 1;
        if(i == 0){
            pre_i = (int)(S.size()) - 1;
        }
        if(S[pre_i] == S[i]){
            if (i == 0 && last_changed){
                continue;
            }
            if(changed[pre_i]){
                continue;
            }
            count += 1LL;
            changed[i] = true;
        }
    }
    return count;
}

int main(){
    string S;
    cin >> S;
    LL K;
    cin >> K;
    LL ans = 0LL;

    vector<bool> changed(S.size(), false);
    LL count = counting(S, changed, true);
    if (K == 1LL){
        cout << count << endl;
        return 0;
    }

    bool last_changed = changed[S.size() - 1];
    REP(i, S.size()){
        changed[i] = false;
    }
    LL count_2 = counting(S, changed, last_changed);

    if(last_changed == changed[S.size() - 1]){
        ans = count + count_2 * (K - 1LL);
    }else{
        LL n_even = (K / 2LL);
        LL n_odd = K  - n_even;
        ans = count * n_odd;
        ans += count_2 * n_even;

    }
    cout << ans << endl;
    return 0;
}