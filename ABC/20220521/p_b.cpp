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
    vector<pair<int, int>> A(N);
    int max_a = -1;
    REP(i, N){
        int a;
        cin >> a; 
        A[i] = {a, 0};
        chmax(max_a, a);
    }

    REP(i, K){
        int b;
        cin >> b;
        A[b-1].second += 1;
    }


    map<int, int> val_map;
    REP(i, N){
        pair<int, int> a = A[i];
        // cout << a.first << ", " << a.second << endl;
        if(val_map.find(a.first) != val_map.end()){
            val_map[a.first] += a.second;
        }else{
            val_map[a.first] = a.second;
        }
    }

    if(val_map[max_a] == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    

    return 0;
}