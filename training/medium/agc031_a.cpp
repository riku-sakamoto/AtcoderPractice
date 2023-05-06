#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
#include <atcoder/modint>
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

using namespace atcoder;
using mint = modint1000000007;


int main(){
    int N;
    cin >> N;
    vector<char> chars(N);
    REP(i, N){
        cin >> chars[i];
    }

    map<char, mint> dict;
    REP(i, N){
        if(dict.find(chars[i]) != dict.end()){
            dict[chars[i]] += mint(1LL);
        }else{
            dict[chars[i]] = mint(1LL);
        }
    }

    mint ans = mint(1LL);
    for(auto v: dict){
        ans *= (v.second + mint(1LL));
    }
    cout << ans.val() - 1 << endl;
    return 0;
}