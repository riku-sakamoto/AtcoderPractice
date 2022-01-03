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
    string X;
    cin >> X;

    int N = X.size();
    vector<int> sums(N, 0);
    int tmp = 0;
    REP(i, N){
        tmp += X[i] - '0';
        sums[i]= tmp;
    }    
    

    deque<int> ans;
    int kurikosi = 0;
    for(int i=N-1; i>=0; --i){
        int _n = (sums[i] + kurikosi) % 10;
        ans.push_front(_n);
        kurikosi = (sums[i] + kurikosi) / 10;
    }
    if(kurikosi != 0){
        cout << kurikosi;
    }
    while (!ans.empty())
    {
        int val = ans.front(); ans.pop_front();
        cout << val;
    }
    cout << endl;
    
    return 0;
}