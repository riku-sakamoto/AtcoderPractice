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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<int>> charMap(26, vector<int>(N, N+1));

    REPREV(i, N){
        int j = S[i] - 'a';
        REP(k, 26){
            if(j==k){
                charMap[k][i] = i;
            }else{
                if(i != N-1)charMap[k][i] = charMap[k][i+1];
                else charMap[k][i] = N+1;
            }
        }
    }

    // REP(i, N){
    //     cout << charMap[2][i] << endl;
    // }

    string ans = "";
    int words = 0;
    int index = 0;
    while(words < K){
        int minIndex = N - K + words;
        bool ok = false;
        REP(j, 26){
            FOR(i, index, N){
                if(charMap[j][i] <= minIndex){
                    ans += 'a' + j;
                    words += 1;
                    index = charMap[j][i] + 1;
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
    }

    cout << ans << endl;
    return 0;
    
}