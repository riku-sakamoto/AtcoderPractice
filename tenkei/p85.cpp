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

queue<pair<LL, LL>> searchPair(LL K, LL minK){
    LL maxk = 1;
    vector<bool> used;
    used.push_back(false);
    while(maxk*maxk <= K){
        used.push_back(false);
        ++maxk;
    }

    LL k = 1;
    queue<pair<LL, LL>> que;
    while(k <= maxk){
        if(used[k] == true){
            ++k;
            continue;
        }

        if(K % k == 0){
            if(K / k >= k){
                if(k >= minK){
                    que.push({k, K / k});
                }
            }else{
                break;
            }
        }else{
            LL j = 1;
            while(j * k < maxk){
                used[j * k] = true;
                ++j;
            }
        }
        ++k;
    }

    return que;
}


int main(){
    LL K;
    cin >> K;

    queue<pair<LL, LL>> que = searchPair(K, 1);
    
    LL ans = 0;
    while(!que.empty()){
        pair<LL, LL> pair1 = que.front(); que.pop();
        queue<pair<LL, LL>> que2 = searchPair(pair1.second, pair1.first);
        ans += que2.size();
    }

    cout << ans << endl;

    return 0;
}