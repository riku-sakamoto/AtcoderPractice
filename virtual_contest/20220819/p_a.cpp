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
    vector<string> vec(4);
    REP(i, 4){
        cin >> vec[i];
    }

    map<string, int> map_c;
    map_c["H"] = 0;
    map_c["2B"] = 0;
    map_c["3B"] = 0;
    map_c["HR"] = 0;

    REP(i, 4){
        map_c[vec[i]] += 1;
    }

    for(auto p: map_c){
        if(p.second != 1){
            no();
            return 0;
        }
    }
    yes();
    return 0;
}