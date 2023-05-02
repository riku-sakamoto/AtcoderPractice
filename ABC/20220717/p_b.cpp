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
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<pair<int, int>> A(N);
    vector<pair<int, int>> B(N);
    vector<pair<int, int>> AB(N);
    vector<int> nums(N);
    REP(i, N){
        int val;
        cin >> val;
        A[i] = {-1*val, i+1};
    }
    REP(i, N){
        int val;
        cin >> val;
        B[i] = {-1*val, i+1};
    }
    REP(i, N){
        int val = A[i].first + B[i].first;
        AB[i] = {val, i+1};
    }
    
    set<int> passed;
    priority_queue<int, vector<int>, greater<int>> que;

    // auto comp = [](pair<int, int> l, pair<int, int> r){return (l.first > r.first || l.second < r.second);};
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(AB));
    // REP(i, N){
    //     cout << AB[i].first << ", " << AB[i].second << endl;
    // }

    REP(i, X){
        auto target = A[i];
        que.push(target.second);
        passed.insert(target.second);
    }

    int j = 0;
    int i = 0;
    while(j < Y) {
        auto target = B[i];
        if(passed.find(target.second) == passed.end()){
            que.push(target.second);
            passed.insert(target.second);
            ++j;
        }
        ++i;
    }


    j = 0;
    i = 0;
    while(j < Z){
        auto target = AB[i];
        if(passed.find(target.second) == passed.end()){
            que.push(target.second);
            passed.insert(target.second);
            ++j;
        }
        ++i;
    }

    while(!que.empty()){
        int val = que.top(); que.pop();
        out(val);
    }

    return 0;
}