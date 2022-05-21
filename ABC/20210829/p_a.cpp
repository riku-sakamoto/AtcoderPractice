#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    double A;
    cin >> A;

    int X = int(A);
    int Y = (A - X)*10;

    if( Y >= 0 && Y <= 2){
        cout << X << "-" << endl;
    } else if(Y >= 3 && Y <= 6){
        cout << X << endl;
    } else if(Y >= 7 && Y <= 9){
        cout << X << "+" << endl;
    }

    return 0;
}