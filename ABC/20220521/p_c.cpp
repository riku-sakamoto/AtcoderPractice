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

void dfs(vector<bool>& order_box, int num){
    if(order_box[num] == false){
        order_box[num] = true;
        return;
    }else{
        dfs(order_box, num + 10);
    }
}

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N)cin >> S[i];

    vector<int> elapsed;
    REP(first_val, 10){
        vector<int> order;
        REP(j, N){
            REP(k, 10){
                int val = S[j][k] - '0';
                if(val == first_val){
                    order.push_back(k);
                }
            }
        }

        sort(ALL(order));

        vector<bool> order_box(2000, false);
        REP(j, N){
            dfs(order_box, order[j]);
        }

        int time = -1;
        REP(j, 2000){   
            if(order_box[j] == true){
                chmax(time, j);
            }
        }

        elapsed.push_back(time);
    }

    sort(ALL(elapsed));
    int ans = elapsed[0];
    cout << ans << endl;

    return 0;
}