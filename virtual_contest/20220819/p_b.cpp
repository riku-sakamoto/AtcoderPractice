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
    map<char, int> map_c;
    map_c['A'] = 0;
    map_c['B'] = 0;
    map_c['C'] = 0;
    map_c['D'] = 0;
    map_c['E'] = 0;
    map_c['F'] = 0;

    for(auto c : S){
        map_c[c] += 1;
    }

    cout << map_c['A'] << ' ';
    cout << map_c['B'] << ' ';
    cout << map_c['C'] << ' ';
    cout << map_c['D'] << ' ';
    cout << map_c['E'] << ' ';
    cout << map_c['F'] << endl;
    return 0;
}