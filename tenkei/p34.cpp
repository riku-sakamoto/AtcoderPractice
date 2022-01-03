#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
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
    int N, K;
    cin >> N >> K;
    vector<LL> a(N, 0);
    REP(i, N)cin >> a[i];
        
    map<LL, int> kind;
    int ans = 0;
    int cnt = 0;

    // 初期化
    REP(i, N){
        kind[a[i]] = 0;
    }

    int j = 0;
    bool start = true;
    REP(i, N){
        if(start){
            while(j < N){
                if(kind.at(a[j]) == 0 && cnt==K)break;
                if(kind.at(a[j]) == 0) cnt+=1;
                kind.at(a[j]) += 1;
                chmax(ans, j - i + 1);
                j++;
            }
        }

        start = false;
        kind.at(a[i]) -= 1;
        if(kind.at(a[i]) == 0){
            cnt -= 1;
            start = true;
        }
    }

    cout << ans << endl;
    return 0;
}