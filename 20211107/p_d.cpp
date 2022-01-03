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

LL gcd(LL a, LL b){
    if(b == 0) {return a;}
    LL r = a % b;

    return gcd(b, r);
}

int main(){
    int N;
    cin >> N;
    vector<pair<LL, LL>> coords;
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }
    
    set<pair<LL, LL>> answers;
    REP(i, N){
        REP(j, N){
            if(i == j){continue;}

            LL dx = coords[i].first - coords[j].first;
            LL dy = coords[i].second - coords[j].second;
            LL abs_dx = abs(dx);
            LL abs_dy = abs(dy);

            LL d_gcd= gcd(abs_dx, abs_dy);

            answers.insert({dx / d_gcd, dy / d_gcd});
            answers.insert({-dx / d_gcd, -dy / d_gcd});
            
        }
    }


    cout << answers.size() << endl;
    return 0;
}