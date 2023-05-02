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
    string S;
    string T;
    cin >> N;
    cin >> S >> T;

    int count_1 = 0;
    int count_0 = 0;
    set<int> idxes_1;
    set<int> idxes_0;
    REP(i, N){
        if(S[i] == '0'){
            count_0 += 1;
            idxes_0.insert(i);
        }else{
            count_1 += 1;
            idxes_1.insert(i);
        }
    }



    int ans = 0;
    REP(i, N){
        if(S[i] == T[i])continue;

        if(S[i] == '0'){
            if(count_1 == 0){
                out(-1);
                return 0;
            }

            ++ans;
            count_1 -= 1;
            count_0 += 1;

            int tmp_i = *(idxes_1.lower_bound(i));
            S[tmp_i] = '0';
            S[i] = '1';
            idxes_1.erase(tmp_i);
            idxes_0.erase(i);
            idxes_0.insert(tmp_i);

            // cout << i << ", " << tmp_i << endl;
            continue;
        }

        if(S[i] == '1'){
            if(count_0 == 0){
                out(-1);
                return 0;
            }

            ++ans;
            count_0 -= 1;
            count_1 += 1;

            int tmp_i = *(idxes_0.lower_bound(i));
            S[tmp_i] = '1';
            S[i] = '0';
            idxes_0.erase(tmp_i);
            idxes_1.erase(i);
            idxes_1.insert(tmp_i);

            // cout << i << ", " << tmp_i << endl;
            continue;
        }
    }

    out(ans);
    return 0;
}