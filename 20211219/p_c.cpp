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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pairsT;
    int a, b;
    REP(i, M){
        cin >> a >> b;
        pairsT.push_back({a, b});
        pairsT.push_back({b, a});
    }
    vector<vector<int>> routesA(N+1, vector<int>());
    int c, d;
    REP(i, M){
        cin >> c >> d;
        routesA[c].push_back(d);
        routesA[d].push_back(c);
    }
 
    vector<int> nums(N, 0);
    REP(i, N){
        nums[i] = i + 1;
    }

    REP(i, N+1){
        sort(ALL(routesA[i]));
    }

    int m = pairsT.size();
    bool ans = false;
    do{
        bool _tmp = true;
        REP(_i, m){
            int i = pairsT.at(_i).first;
            int j = pairsT.at(_i).second;
 
            int pi= nums.at(i-1);
            int pj = nums.at(j-1);
 
            if(binary_search(ALL(routesA.at(pi)), pj) && binary_search(ALL(routesA.at(pj)), pi)){
                continue;
            }else{
                _tmp = false;
                break;
            }
        }
 
        if(_tmp){
            ans = true;
            break;
        }
 
    }while(next_permutation(ALL(nums)));
 
 
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}