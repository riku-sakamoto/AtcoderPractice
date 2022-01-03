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
    int K;
    LL Large = 1E9 + 7;
    cin >> K;

    vector<LL> answers(K+1, 0);

    if(K % 9 != 0){
        cout << 0 << endl;
        return 0;
    }

    REP(i, K+1){
        if(i == 0){
            answers[i] = 1;
            continue;
        }

        int min_index = max({0, i-9});
        FOR(j, min_index, i){
            answers[i] = (answers[i] % Large + answers[j] % Large) % Large;
        }
    }

    cout << answers[K] << endl;
    return 0;

}