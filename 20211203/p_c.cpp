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
#define REP(i,n) for(LL i=0;i<(n);i++)
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    LL N, A, B;
    cin >> N >> A >> B;
    LL P, Q, R ,S;
    cin >> P >> Q >> R >> S;

    int rows = int((Q - P) + 1);
    int cols = int((S - R) + 1);
    vector<vector<char>> ans(rows, vector<char>(cols, '.'));

    FOR(i, P, Q + 1){
        FOR(j, R, S + 1){
            LL l1 = max<LL>({1, 1 + (A - B)});
            LL r1 = min<LL>({N, N + (A - B)});
            LL l2 = max<LL>({1, 1 + (B - A)});
            LL r2 = min<LL>({N, N + (B - A)});

            if( i >= l1 && i <= r1 && j >= l2 && j <= r2){
                LL k1 = i - A;
                LL k2 = j - B;
                if(k1 == k2){
                    ans[i-P][j-R] = '#';
                }
            }

            LL l3 = max<LL>({1, (A + B) - N});
            LL r3 = min<LL>({N, (A + B) - 1});
            LL l4 = max<LL>({1, (A + B) - N});
            LL r4 = min<LL>({N, (A + B) - 1});

            if( i >= l3 && i <= r3 && j >= l4 && j <= r4){
                LL k3 = i - A;
                LL k4 = B - j;
                if(k3 == k4){
                    ans[i-P][j-R] = '#';
                }
            }
        }
    }

    REP(i, rows){
        REP(j, cols){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
       
}