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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    string S;
    cin >> S;

    vector<string> patterns;
    patterns.push_back("oxx");
    patterns.push_back("xxo");
    patterns.push_back("xox");

    REP(i, 3){
        bool ok = true;
        string target = patterns[i];

        int k = 0;
        REP(j, S.size()){
            if(S[j] != target[k]){
                ok = false;
                break;
            }
            k += 1;
            k %= 3;
        }

        if(ok){
            cout << "Yes" << endl;
            return 0;
        }

    }

    cout << "No" << endl;
    return 0;
    
}