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
    LL K;
    cin >> N >> K;
    vector<int> A(N, 0);
    REP(i, N){
        int a;
        cin >> a;
        A[i] = a - 1;
    }

    vector<int> towns;
    set<int> visited;
    int now = 0;
    while(true){
        if(visited.find(now) != visited.end()){
            break;
        }
        visited.insert(now);
        towns.push_back(now);
        now = A[now];
    }

    int len = 0;
    REP(i, towns.size()){
        if(towns[i] == now){
            break;
        }
        len += 1;
    }

    int cycle = (towns.size() - len);
    // cout << "len" << len << endl;
    // cout << "cycle" << cycle << endl;

    int ans;
    if(K <= (LL)len){
        ans = towns[(int)K];
    }else{
        LL r = (K - (LL)len) % (LL)cycle;
        ans = towns[(int)len + (int)r];
    }

    cout << ans + 1 << endl;
    return 0;
}