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


LL searchKsmallerX(multiset<LL>& groups, int k, LL x){
    // auto itr = groups.upper_bound(x);
    // // stdはだめ
    // // auto itr = upper_bound(ALL(groups), x);

    bool ng=false;
    auto itr = groups.upper_bound(x);
    while(k--){
        if(itr==groups.begin()){
            ng=true;break;
        }
        itr--;
    }
    if(ng)return -1;
    return *itr;
    // REP(i, k){
    //     if(itr == groups.begin()){
    //         return -1;
    //     }        
    //     --itr;
    // }
    // return *itr;
}

LL searchKlargerX(multiset<LL>& groups, int k, LL x){
    bool ng = false;
    auto itr = groups.lower_bound(x);
    while(k--){
        if(itr==groups.end()){
            ng=true;
            break;
        }
        if(k==0)break;
        itr++;
    }
    if(ng)return -1;
    return *itr;
    // auto itr = groups.lower_bound(x);
    // // auto itr = lower_bound(ALL(groups), x);
    // REP(i, k-1){
    //     if(itr == groups.end()){
    //         return -1;
    //     }        
    //     itr++;
    // }

    // if(itr == groups.end()){
    //     return -1;
    // }
    // return *itr;
}


int main(){
    int Q;
    multiset<LL> groups;
    queue<LL> ans;
    cin >> Q;
    REP(j, Q){
        int i, k;
        LL x;
        cin >> i;
        if(i == 1){
            cin >> x;
            groups.insert(x);
        }else if(i == 2){
            cin >> x;
            cin >> k;
            LL val = searchKsmallerX(groups, k, x);
            ans.push(val);
        }else{
            cin >> x;
            cin >> k;
            LL val = searchKlargerX(groups, k, x);
            ans.push(val);
        }
    }

    while(!ans.empty()){
        int val = ans.front(); ans.pop();

        cout << val << endl;
    }

    // groups.insert(3);
    // groups.insert(5);
    // auto itr = lower_bound(ALL(groups), 1);
    // cout << *itr << endl;
    // cout << *(--groups.end()) << endl;
    return 0;
}