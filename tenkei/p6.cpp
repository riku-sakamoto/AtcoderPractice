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
 
int K, N;
string S;

pair<char, int> search(vector<vector<int>> indexesMap, int sentence_index, int target_index){
    int left_counts = 0;
    REP(i, 27){
        int index = indexesMap[i][sentence_index];
        left_counts = S.size() - index;
        if(left_counts >= K - target_index){
            return pair<char, int>(char('a' + i), index);
        }
    }
}



int main(){

    cin >> N >> K;
    cin >> S;
    string ans = "";
    vector<vector<int>> indexesMap(27, vector<int>((int)S.size(), (int)S.size()));

    for(int i=S.size()-1; i >= 0; i--){
        char c = S[i];
        int index = (int)(c - 'a');

        REP(j, 27){
            if(j == index){
                indexesMap[index][i] = i;
            }else{
                if(i + 1 < S.size()){
                    indexesMap[j][i] = indexesMap[j][i + 1];
                }else{
                    indexesMap[j][i] = (int)S.size();
                }
            }
        }
    }

    // REP(i, S.size()){
    //     REP(j, 27){
    //         cout << indexesMap[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    int si= 0;
    REP(i,K){
        pair<char, int> cpair = search(indexesMap ,si, i);
        si = cpair.second + 1;
        // cout << cpair.first << endl;
        ans += cpair.first;
    }


    cout << ans << endl;
    return 0;
    
}