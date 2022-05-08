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
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<char>> white_tile(A, vector<char>(B, '.'));
    vector<vector<char>> black_tile(A, vector<char>(B, '#'));

    vector<vector<char>> tile(N*A, vector<char>(N*B, '.'));

    REP(i, N*A){
        REP(j, N*B){
            int ni = i / A;
            int nj = j / B;
            if(ni % 2 == 0 && nj % 2 == 0){
                cout << '.';
            }
            else if(ni % 2 == 1 && nj % 2 == 0){
                cout << '#';
            }
            else if(ni % 2 == 0 && nj % 2 == 1){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl; 
    }
    return 0;
}