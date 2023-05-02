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
    int N;
    cin >> N;
    map<string, pair<int, int>> dict;
    REP(i, N){
        string s;
        cin >> s;

        string key = "";
        bool is_q = false;
        if(s[0] == '!'){
            key = s.substr(1);
            is_q = true;
        }else{
            key = s;
        }
        
        if(dict.find(key) != dict.end()){
            auto val = dict[key];
            if(is_q){
                val.second += 1;
            }else{
                val.first += 1;
            }
            dict[key] = val;
        }else{
            if(is_q){
                dict[key] = {0, 1};
            }else{
                dict[key] = {1, 0};
            }
        }
    }

    for(auto item: dict){
        // cout << item.first << ", " << item.second.first << ", " << item.second.second << endl;
        if(item.second.first > 0 && item.second.second > 0){
            cout << item.first << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;


    return 0;
}