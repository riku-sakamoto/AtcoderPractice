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
    vector<vector<int>> conditions(M, vector<int>());
    REP(i, M){
        int k;
        cin >> k;
        REP(j, k){
            int s;
            cin >> s;
            --s;
            conditions[i].push_back(s);
        }
    }
    vector<int> p(M, 0);
    REP(i, M){
        cin >> p[i];
    }

    LL val = 0LL;
    vector<int> switchs(N, 0);
    LL answer = 0;
    while(val < (1LL << N)){
        REP(i, N){
            if((val & (1 << i)) != 0){
                switchs[i] = 1;
            }else{
                switchs[i] = 0;
            }
        }

        bool isOk = true;
        REP(i, M){
            auto cond = conditions[i];
            int ans = 0;
            for(auto v: cond){
                ans += switchs[v];
            }

            ans = ans % 2;
            if(ans != p[i]){
                isOk = false;
                break;
            }
        }
        if(isOk){
            answer += 1;
        }

        val++;
    }

    out(answer);
    
    return 0;
}