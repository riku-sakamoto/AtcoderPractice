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
    string S;
    cin >> S;

    vector<int> counts;
    char c = 'a';
    while(c <= 'z'){
        counts.push_back(0);
        c += 1;
    }

    REP(i, S.size()){
        int idx = S[i] - 'a';
        counts[idx] += 1;
    }

    REP(i, counts.size()){
        if (counts[i] == 0){
            char tmp_c = 'a' + i;
            cout << S << tmp_c << endl;
            return 0;
        }
    }

    REPREV(i, S.size()){
        char tmp = S[i];
        int idx = tmp - 'a';
        counts[idx] -= 1;

        tmp += 1;
        while(tmp <= 'z'){
            int tmp_idx = tmp - 'a';
            if(counts[tmp_idx] == 0){
                cout << S.substr(0, i) << tmp << endl;
                return 0;
            }
            tmp += 1;
        }

        // cout << S[i] << endl;
    }
    cout << -1 << endl;
    return 0;
}