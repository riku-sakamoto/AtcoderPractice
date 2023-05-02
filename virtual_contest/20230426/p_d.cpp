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
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    string S;
    cin >> S;
    int N = S.size();

    reverse(ALL(S));
    LL count = 0;

    map<char, LL> counts;
    map<char, int> char_map;
    REP(i, N - 2){
        if (char_map.find(S[i]) == char_map.end()){
            char_map[S[i]] = 1;
        }else{
            char_map[S[i]] += 1;
        }
        
        if(S[i] != S[i + 2] && S[i + 2] == S[i + 1]){
            LL tmp_count = i + 1LL - char_map[S[i + 1]];
            if (counts.find(S[i + 1]) == counts.end()){
                counts[S[i + 1]] = tmp_count;
            } else{
                counts[S[i + 1]] += tmp_count;
            }
            // char_map[S[i]] = 0;
            int wc = char_map[S[i + 1]];
            char_map = {};
            char_map[S[i + 1]] = i + 1;
        }
    }

    for(auto item: counts){
        // cout << item.first << ", " << item.second << endl;
        count += item.second;
    }

   cout << count << endl;
    return 0;
}