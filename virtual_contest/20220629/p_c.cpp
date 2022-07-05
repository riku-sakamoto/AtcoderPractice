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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}

int main(){
    string S;
    cin >> S;
    int N;
    cin >> N;

    int num = S.size();
    vector<int> orders;
    REP(i, num){
        orders.push_back(i);
    }

    REP(i, N){
        int l, r;
        cin >> l >> r;

        vector<int> new_orders(num);
        REP(j, num){
            if (j >= l-1 && j < r){
                int back = j - (l - 1);
                new_orders[j] = orders[r - 1 - back];
            }else{
                new_orders[j] = orders[j];
            }
        }

        // REP(j, num){
        //     cout << S[new_orders[j]];
        // }
        // cout << endl;
        orders = new_orders;
    }

    REP(i, num){
        int idx = orders[i];
        cout << S[idx];
    }
    cout << endl;


    return 0;
}