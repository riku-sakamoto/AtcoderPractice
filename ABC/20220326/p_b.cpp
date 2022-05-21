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

int main(){
    int N;
    cin >> N;
    set<int> A;
    int max_val = 0;
    REP(i, N){
        int a;
        cin >> a;
        A.insert(a);
        chmax(max_val, a);
    }

    int start = 0;
    bool isFind = false;
    for(auto x : A){
        if(start == x){
            ++start;
            continue;
        }else{
            isFind = true;
            break;
        }
    }

    if(isFind){
        cout << start << endl;
    }else{
        cout << max_val + 1 << endl;
    }
    return 0;
}