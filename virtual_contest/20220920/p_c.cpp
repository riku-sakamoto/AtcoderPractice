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
    vector<string> S(N);
    REP(i, N){
        cin >> S[i];
    }

    int min_time = 1 << 20;
    REP(c, 10){
        set<int> times;
        REP(i, N){
            int time;
            REP(j, 10){
                if(S[i][j] - '0' == c){
                    time = j;
                    break;
                }
            }
            while(times.find(time) != times.end()){
                time += 10;
            }
            times.insert(time);
        }
        
        int max_time = 0;
        for(auto it: times){
            chmax(max_time, it);
        }

        chmin(min_time, max_time);
    }
    out(min_time);

    return 0;
}