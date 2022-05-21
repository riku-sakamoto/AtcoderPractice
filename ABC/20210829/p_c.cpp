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
    LL N;
    cin >> N;

    string ans = "";
    int k = 0;
    
    while(true){
        if(N==0){
            break;
        }

        bool a = (N%2 == 1);
        if (a == true){
            if(k==0){
                ans += "A";
            }else{
                ans += "BA";
            }
        } else{
            if(k != 0){
                ans +="B";
            }
        }
        N = N >> 1;
        k += 1;

    }

    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i];
    }

    cout << endl;
    return 0;
}