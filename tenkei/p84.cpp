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
    vector<char> vec(N);
    REP(i, N)cin>>vec[i];

    int startIdx = 0;
    LL ans = 0;
    while(startIdx < N){
        set<char> charsets;
        int idx = startIdx;
        bool find = false;
        while(idx < N){
            charsets.insert(vec[idx]);
            if(charsets.size() == 2){
                find = true;
                break;
            }

            ++idx;

            // if(charsets.size()< 2){
            //     ++idx;
            //     continue;
            // }else{
            //     find = true;
            //     break;
            // }
        }


        if(find){
            // cout << idx << endl;

            // start : startIdx to idx - 1
            // end : idx to N - 1
            ans += LL(N - idx) * LL(idx - startIdx);
            startIdx = idx;
        }else{
            break;
        }
        
    }

    cout << ans << endl;
    return 0;
}