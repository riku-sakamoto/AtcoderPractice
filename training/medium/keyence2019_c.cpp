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
    vector<LL> A(N);
    vector<LL> B(N);
    REP(i, N)cin>>A[i];
    REP(i, N)cin>>B[i];

    priority_queue<LL> plus_que;
    priority_queue<LL, vector<LL>, greater<LL>> minus_que;
    REP(i, N){
        LL tmp = A[i] - B[i];
        if(tmp >= 0){
            plus_que.push(tmp);
        }else{
            minus_que.push(tmp);
        }
    }

    LL plus = 0;
    while(!minus_que.empty()){
        LL minus_val = minus_que.top(); minus_que.pop();
        while(minus_val < 0){
            if(minus_val + plus >= 0){
                plus += minus_val;
                minus_val = 0;
            }else{
                if(plus_que.empty()){
                    out(-1);
                    return 0;
                }
                LL plus_val = plus_que.top(); plus_que.pop();
                plus += plus_val;
            }
        }
    }

    int ans = N - plus_que.size();
    cout << ans << endl;


    return 0;
}
