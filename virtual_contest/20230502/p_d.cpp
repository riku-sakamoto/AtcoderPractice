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
    int N;
    LL X;
    cin >> N >> X;

    vector<LL> barger;
    vector<LL> patty;
    
    REP(i, N + 1){
        if(i == 0){
            barger.push_back(1LL);
            patty.push_back(1LL);
            continue;
        }

        LL num= 2LL * barger[i - 1] + 3LL;
        LL pa = 2LL * patty[i - 1] + 1LL;
        barger.push_back(num);
        patty.push_back(pa);
    }

    LL ans = 0LL;
    int n = N;
    while(true){
        if (n == 0){
            ans += patty[0];
            break;
        }
        if (X <= 1LL){
            break;
        }
        if(X <= barger[n - 1] + 1LL){
            X -= 1LL;
            n -= 1;
            continue;
        }
        if(X <= barger[n - 1] + 2LL){
            ans += patty[n - 1] + 1LL;
            break;
        }
        if(X <= 2LL * barger[n - 1] + 2LL){
            ans += patty[n - 1] + 1LL;
            X -= (2LL + barger[n - 1]);
            n -= 1;
            continue;
        }

        ans += 1LL + 2LL * patty[n - 1];
        break;
    }

    cout << ans << endl;

    return 0;
}