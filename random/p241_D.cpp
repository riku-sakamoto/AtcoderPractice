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

// LL LARGE_VALUE = LLONG_MAX;
LL LARGE_VALUE = (1LL << 62);

LL getKLowerX(multiset<LL>& cont, LL x, int k){
    auto itr = cont.upper_bound(x);
    REP(i, k){
        --itr;
    }
    
    if(*itr == 0){
        return -1;
    }else{
        return *itr;
    }
}

LL getKUpperX(multiset<LL>& cont, LL x, int k){
    auto itr = cont.lower_bound(x);
    REP(i, k-1){
        ++itr;
    }
    if(*itr == LARGE_VALUE){
        return -1;
    }else{
        return *itr;
    }
}


int main(){
    multiset<LL> cont;
    REP(i, 5){
        cont.insert(0);
        cont.insert(LARGE_VALUE);
    }
    queue<LL> que;
    int Q;
    cin >> Q;
    REP(j, Q){
        int i, k;
        LL x;
        cin >> i;
        if(i == 1){
            cin >> x;
            cont.insert(x);
            continue;
        }
        if(i == 2){
            cin >> x >> k;
            LL val = getKLowerX(cont, x, k);
            que.push(val);
            continue;
        }
        if(i == 3){
            cin >> x >> k;
            LL val = getKUpperX(cont, x, k);
            que.push(val);
            continue;
        }
    }

    while(!que.empty()){
        LL val = que.front(); que.pop();
        cout << val << endl;
    }
    return 0;
}