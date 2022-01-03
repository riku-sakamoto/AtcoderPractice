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

int gcd(int a, int b){
    int min_p = min({a, b});
    int max_p = max({a, b});

    if(min_p == 0){
        return max_p;
    }

    return gcd(min_p, max_p%min_p);
}

int main(){
    string S;
    string T;

    cin >> S;
    cin >> T;

    int n = S.size();
    vector<int> changes(n, 0);

    REP(i, n){
        int si = S[i] - '0';
        int ti = T[i] - '0';

        int diff = ti - si;
        if(diff < 0){
            diff += 26;
        }

        changes[i] = diff;
    }

    sort(ALL(changes));

    int x = changes[0];
    bool ans = true;

    FOR(i, 1, n){
        if(changes[i] != x){
            ans = false;
            break;
        }
    }

    if(ans == false){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;

}