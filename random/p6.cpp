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
    string S;
    cin >> N >> K;
    cin >> S;

    int numAlpha = 26;
    vector<vector<int>> wordsSeq(numAlpha, vector<int>(N, N+1));
    for(int j=N-1; j>=0; --j){
        int word = S[j] - 'a';
        REP(i, numAlpha){
            if(i == word){
                wordsSeq[i][j] = j;
            }else{
                if(j != N-1){
                    wordsSeq[i][j] = wordsSeq[i][j+1];
                }
            }
        }
    }

    int index = 0;
    string ans = "";
    REP(k, K){
        int max_index = N - (K - k);
        REP(i, 26){
            if(wordsSeq[i][index] <= max_index){
                ans += ('a' + i);
                index = wordsSeq[i][index] + 1;
                break;
            }
        }
    }

    cout << ans << endl;
    // cout << "a" << endl;
    return 0;
}