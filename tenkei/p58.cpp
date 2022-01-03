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

LL Q = 1E5;

int getY(int val){
    int ans = 0;
    for(char n: to_string(val)){
        ans += n - '0';
    }
    return ans;
}

int proceed(int val){
    int y = getY(val);
    return (val + y) % Q;
}

int main(){
    int N;
    LL K;
    cin >> N >> K;

    vector<int> values;
    set<int> kinds;
    int n_ = N;
    while (true)
    {
        n_ = proceed(n_);
        if(kinds.find(n_) != kinds.end()){
            break;
        }
        values.push_back(n_);
        kinds.insert(n_);
    }

    int period = values.end() - lower_bound(ALL(values), n_);
    int diff = values.size() - period;

    int ans = N;
    if(K <= values.size()){
        ans = values[K-1];
        cout << ans << endl;
        return 0;
    }

    int n = (int)((K - diff) % period);
    REP(i, diff){
        ans = proceed(ans); 
    }

    if(n == 0) n = period;

    REP(i, n){
        ans = proceed(ans); 
    }
    cout << ans << endl;
    return 0;
    
}