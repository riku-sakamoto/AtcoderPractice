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

int main(){
    int Q;
    cin >> Q;
    int pos = 0;
    vector<pair<LL,LL>> Balls;
    queue<LL> ans;
    REP(i, Q){
        int t, x, c;
        cin >> t;
        if(t == 1){
            cin >> x >> c;
            Balls.push_back({x, c});
        }else{
            cin >> c;
            int idx_vec = pos;
            LL val = 0;
            FOR(j, idx_vec, Balls.size()){
                LL score = Balls[j].first;
                LL nums = Balls[j].second;
                if(nums >= c){
                    val += score * c;
                    Balls[j].second = nums - c;
                    pos = j;
                    break;
                }else{
                    val += score * nums;
                    c -= nums;
                }
            }
            ans.push(val);

        }
    }

    while(!ans.empty()){
        LL val = ans.front();
        ans.pop();

        cout << val << endl;
    }

    return 0;
}