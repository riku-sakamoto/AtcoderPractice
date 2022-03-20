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

pair<int, int> changeDir(pair<int, int> dir){
    if(dir.first==1 && dir.second==0){
        return {0, -1};
    }
    if(dir.first==0 && dir.second==-1){
        return {-1, 0};
    }
    if(dir.first==-1 && dir.second==0){
        return {0, 1};
    }
    if(dir.first==0 && dir.second==1){
        return {1, 0};
    }
    return {0, 0};
}

int main(){
    int N;
    cin >> N;
    string T;
    cin >> T;

    pair<int, int> coord = {0, 0};
    pair<int, int> dir = {1, 0};
    REP(i, N){
        char c = T[i];
        if(c == 'S'){
            coord.first += dir.first;
            coord.second += dir.second;
        }else{
            dir = changeDir(dir);
        }
    }

    cout << coord.first << " " << coord.second << endl;
    return 0;
}