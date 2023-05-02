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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> node_to_nodes(N, vector<int>());
    REP(i, M){
        int u, v;
        cin >> u >> v;
        node_to_nodes[u - 1].push_back(v - 1);
        node_to_nodes[v - 1].push_back(u - 1);
    }

    set<set<int>> answers;

    REP(i, N){
        for(auto j: node_to_nodes[i]){
            if( i == j ){continue;}
            for(auto k: node_to_nodes[j]){
                if(j == k){continue;}

                for(auto l: node_to_nodes[k]){
                    if (k == l){continue;}

                    if(i == l){
                        auto v = set({i, j, k});
                        answers.insert(v);
                        // cout << i << ", " << j << ", " << k << endl;
                    }

                }

            }
        }
    }

    int ans = answers.size();
    cout << ans << endl;

    
    return 0;
}