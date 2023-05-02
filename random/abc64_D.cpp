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
    string S;
    cin >> N >> S;

    vector<int> counts;
    int c = 0;
    for(auto k: S){
        if (k =='(')++c;
        if (k ==')')--c;

        counts.push_back(c);
    }

    int min_val = *min_element(ALL(counts));

    if (min_val < 0){
        REP(i, abs(min_val)){
            S.insert(S.begin(), '(');
        }

        c += abs(min_val);
    }
    
    while(c != 0){
        S.push_back(')');
        --c;
    }

    for(auto k: S){
        cout << k;
    }
    cout << endl;

    return 0;
}