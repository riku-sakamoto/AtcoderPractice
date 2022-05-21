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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, 0);
    REP(i, N){
        cin >> A[i];
    }

    sort(ALL(A));

    int x;
    queue<int> ans;
    REP(i, Q){
        cin >> x;
        
        int num = A.end() - lower_bound(ALL(A), x);
        ans.push(num);
    }

    while (!ans.empty())
    {
        int val = ans.front();ans.pop();
        cout << val << endl;
        /* code */
    }
    return 0;
    
}