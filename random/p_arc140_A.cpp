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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int N, K;

vector<string> countString(string S,int k){
    vector<string> blockStr;
    string tmpS = "";
    REP(i, N){
        tmpS += S[i];
        if((i+1) % k == 0){
            blockStr.push_back(tmpS);
            tmpS = "";
        }
    }

    return blockStr;
}

vector<char> fequentChars(vector<string> targets){
    int stringSize = targets[0].size();

    vector<char> chars;
    REP(i, stringSize){
        map<char, int> countChars;
        for(auto tmpS: targets){
            if(countChars.find(tmpS[i]) == countChars.end()){
                countChars[tmpS[i]] = 1;
            }else{
                countChars[tmpS[i]] += 1;
            }
        }

        char max_char = ' ';
        int max_num = 0;
        for(auto item: countChars){
            if(max_num < item.second){
                max_num = item.second;
                max_char = item.first;
            }
        }

        chars.push_back(max_char);
    }

    return chars;
}



int main(){
    cin >> N >> K;
    string S;
    cin >> S;

    int ans = N;
    REPREV(i, N){
        if(i == 0){continue;}
        if(N % i != 0){continue;}

        vector<string> blocks =  countString(S, i);
        vector<char> chars =  fequentChars(blocks);

        int steps = 0;
        for(auto block: blocks){
            REP(i, block.size()){
                if(block[i] != chars[i]){
                    steps += 1;
                }
            }
        }

        // cout << targetS << ", " << steps << endl;
        if(steps <= K){
            chmin(ans, i);
        }
    }

    out(ans);
    return 0;
}