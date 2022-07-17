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
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    queue<string> que;

    int tmp_A = 0;
    int tmp_B = 0;
    REP(i, N){
        if(S[i] == 'c'){
            que.push("No");
            continue;
        }

        if(S[i] == 'a'){
            if(tmp_A + tmp_B < A + B){
                que.push("Yes");
                ++tmp_A;
            }else{
                que.push("No");
            }
            continue;
        }

        if(S[i] == 'b'){
            if((tmp_A + tmp_B < A + B) && (tmp_B < B)){
                que.push("Yes");
                ++tmp_B;
            }else{
                que.push("No");
            }
        }
    }

    while(!que.empty()){
        string val= que.front();que.pop();
        out(val);
    }
    return 0;
}