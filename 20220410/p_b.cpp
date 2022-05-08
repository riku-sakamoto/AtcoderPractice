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
    vector<pair<string, string>> Names(N);
    REP(i, N){
        string s, t;
        cin >> s >> t;
        Names[i] = {s, t};
    }

    vector<string> NickNames;
    REP(i, N){
        bool isPossible = true;
        string nickName = Names[i].first;
        REP(j, N){
            if(i == j){continue;}

            if(Names[j].first == nickName || Names[j].second == nickName){
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            NickNames.push_back(nickName);
            continue;
        }

        nickName = Names[i].second;
        isPossible = true;
        REP(j, N){
            if(i == j){continue;}

            if(Names[j].first == nickName || Names[j].second == nickName){
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            NickNames.push_back(nickName);
            continue;
        }else{
            break;
        }
    }


    if(NickNames.size() != N){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}