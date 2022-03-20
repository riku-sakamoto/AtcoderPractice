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

LL getNum(int n){
    LL m = 1;
    REP(i, n){
        m *= 10;
    }

    return 10;
}


int searchIdx(vector<char>& vec, char c){
    REP(i, 3){
        if(vec[i] == c){
            return i;
        }
    }
    return 0;
}

int main(){
    vector<char> Si;
    REP(i, 3){
        char s;
        cin >> s;
        Si.push_back(s);
    }

    vector<char> Ti;
    REP(i, 3){
        char t;
        cin >> t;
        Ti.push_back(t);
    }

    LL k = 0;
    while(true){
        if(Si == Ti){
            break;
        }

        REP(i, 3){
            if(Si[i] == Ti[i])continue;

            int idx = searchIdx(Si, Ti[i]);
            // cout << idx << endl;
            int tmp1 = Si[i];
            int tmp2 = Si[idx];
            Si[i] = tmp2;
            Si[idx] = tmp1;
            // cout << Si[0] << ", " << Si[1] << ", " << Si[2] << endl;
            ++k;
        }

        if(k == 3){
            break;
        }

    }
    // cout << k << endl;


    if (k == 0){
        cout << "Yes" << endl;
        return 0;
    }
    LL m = (getNum(18) - k) % 2;
    // cout << m << endl; 
    if (m == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}