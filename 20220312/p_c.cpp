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

    vector<pair<LL, LL>> Coords;
    REP(i, N){
        LL x, y;
        cin >> x >> y;
        Coords.push_back({x, y});
    }

    string S;
    cin >> S;
    map<pair<LL, LL>, char> dirMap;
    REP(i, N){
        dirMap[Coords[i]] = S[i];
    }

    sort(ALL(Coords));
    // REP(i, N){
    //     cout << Coords[i].first << ", " << Coords[i].second << endl;
    // }
    map<LL, char> Direction;

    REP(i, N){
        LL x = Coords[i].first;
        LL y = Coords[i].second;
        char dir = dirMap[{x, y}];

        if(Direction.find(y) == Direction.end()){
            if(dir == 'R'){
                Direction[y] = S[i];
            }
            continue;
        }

        if(dir == 'L'){
            cout << "Yes" << endl;
            return 0;
        }

    }

    cout << "No" << endl;
    return 0;
}