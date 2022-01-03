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
    int N;
    cin >> N;
    vector<set<int>> tree(N+1);

    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }

    int count = 0;
    FOR(i, 1, N+1){
        int num = tree[i].size();
        if(num == N - 1){
            count += 1;
            continue;
        }
        if(num == 1){
            continue;   
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    if(count == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
    
}