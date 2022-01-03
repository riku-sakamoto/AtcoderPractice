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
    int Q;
    cin >> Q;

    vector<LL> fronts;
    vector<LL> backs;

    queue<LL> ans;
    int t;
    LL x;
    REP(i, Q){
        cin >> t;
        if(t == 1){
            cin >> x;
            fronts.push_back(x);
        }

        if(t == 2){
            cin >> x;
            backs.push_back(x);
        }

        if(t == 3){
            cin >> x;

            if(x <= fronts.size()){
                int index = fronts.size() - x;
                ans.push(fronts[index]);
            }else{
                x -= fronts.size();
                ans.push(backs[x-1]);
            }

        }
    }

    while(!ans.empty()){
        int val = ans.front();ans.pop();
        cout << val << endl;
    }
    return 0;
    
}