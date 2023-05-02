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

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> image(H, vector<char>(W, '.'));
    REP(i, H){
        REP(j, W){
            cin >> image[i][j];
        }
    }

    vector<vector<char>> newImage(2*H, vector<char>(W, '.'));

    REP(i, 2*H){
        REP(j, W){
            newImage[i][j] = image[i/2][j];
        }
    }

    REP(i, 2*H){
        REP(j, W){
            cout << newImage[i][j];
        }
        cout << endl;
    }
    
    return 0;
}   