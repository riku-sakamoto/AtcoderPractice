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
    vector<LL> A(N, 0LL);
    REP(i, N){
        cin >> A[i];
    }
    sort(ALL(A));

    map<LL, int> counts;
    vector<LL> que;
    REPREV(i, N){
        if(counts.find(A[i]) == counts.end()){
            counts[A[i]] = 1;
        }else{
            counts[A[i]] += 1;
        }

        if(counts[A[i]] >= 2){
            que.push_back(A[i]);
            counts[A[i]] -= 2;
        }

        if(que.size() == 2){
            break;
        }
    }

    if (que.size() < 2){
        cout << 0 << endl;
    }else{
        LL ans = que[0] * que[1];
        cout << ans << endl;
    }
    return 0;
}