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
    vector<string> Sa(3, "");
    cin >> Sa[0] >> Sa[1] >> Sa[2];
    vector<string> Ss;
    Ss.push_back("ABC");
    Ss.push_back("ARC");
    Ss.push_back("AGC");
    Ss.push_back("AHC");
    
    sort(ALL(Ss));
    sort(ALL(Sa));

    REP(i, 3){
        if(Ss[i] != Sa[i]){
            cout << Ss[i] << endl;
            return 0;
        }
    }

    cout << Ss[3] << endl;
    return 0;

}