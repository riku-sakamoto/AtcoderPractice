#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
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

    map<string, int> names;
    vector<int> ans;
    REP(i,N){
        string n;
        cin >> n;

        if(names.find(n) != names.end()){
           continue; 
        }else{
            names[n] = 1;
            ans.push_back(i+1);
        }
    }
    
    for(auto val: ans){
        cout << val << endl;
    }

    return 0;
}