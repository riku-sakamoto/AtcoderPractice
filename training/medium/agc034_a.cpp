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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    vector<char> road(N+1, '_');
    REP(i, N){
        cin >> road[i+1];
    }

    bool goal_B = false;
    bool goal_A = false;
    bool can_overlap = false;
    while(true){
        if(road[B-1] == '.' && road[B+1] == '.' && B+1 <= N){
            can_overlap = true;
        }
        if(B == D){
            goal_B = true;
            break;
        }
        if(road[B+1] == '.'){
            B += 1;
            continue;
        }
        if(road[B+1] == '#' && road[B+2] == '.'){
            B += 2;
            continue;
        }
        break;
    }

    while(true){
        if(A == C){
            goal_A = true;
            break;
        }
        if(road[A+1] == '.'){
            if (A+1 != B){
                A += 1;
                continue;
            }
            if(A+1 == B && can_overlap == true){
                A += 1;
                continue;
            }
        }
        if(road[A+1] == '#' && road[A+2] == '.'){
            if (A+2 != B){
                A += 2;
                continue;
            }
            if(A+2 == B && can_overlap == true){
                A += 2;
                continue;
            }
        }
        break;
    }

    if(goal_A && goal_B){
        yes();
    }else{
        no();
    }

    return 0;
}