#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
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
    int N;
    cin >> N;
    map<string, int> election;

    string S;
    REP(i, N){
        cin >> S;
        auto itr = election.find(S);
        if(itr != election.end()){
            itr->second += 1;
        }else{
            election[S] = 1;
        }
    }

    int num = 0;
    string ans = "";

    // cout << "" << endl;
    for(auto itr = election.begin(); itr != election.end(); itr++){
        // cout << itr->first << ":" << itr->second << endl;
        if(num < itr->second){
            ans = itr->first;
            num = itr->second;
        }
    }

    cout << ans << endl;
    return 0;

}