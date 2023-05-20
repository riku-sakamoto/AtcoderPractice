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


string str_slice(int i, int j, string& S){
    int n = j - i;
    return S.substr(i, n);
}



int main(){
    string S;
    cin >> S;
    int N = S.size();

    LL tmp = 0LL;

    set<vector<LL>> calculus;
    while(tmp < (1LL << LL(N - 1LL))){
        vector<int> plus;
        REP(j, N - 1){
            if((tmp & (1 << j)) != 0){
                plus.push_back(j);
            }
        }
        // REP(i, plus.size()){
        //     cout << plus[i] << ",";
        // }
        // cout << endl;

        vector<LL> values;
        int n = plus.size();
        string tmp_s;
        REP(i, n){
            if(i == 0){
                tmp_s = str_slice(0, plus[i] + 1, S);
                values.push_back(stoll(tmp_s));
            }else{
                tmp_s = str_slice(plus[i - 1] + 1, plus[i] + 1, S);
                // out(tmp_s);
                values.push_back(stoll(tmp_s));
            }
        }

        if(n == 0){
            tmp_s = str_slice(0, N, S);
        }else{
            tmp_s = str_slice(plus[n - 1] + 1, N, S);
            // cout << "plus[n - 1] + 1: " << plus[n - 1] + 1 << ", N: "<< N << endl;
        }
        // // out(plus.size());
        // out(plus[n - 1]);
        // out(N);
        // cout << endl;
        values.push_back(stoll(tmp_s));
        // cout << "start: ";
        // REP(i, values.size()){
        //     cout << values[i] << ", ";
        // }
        // cout << endl;
        calculus.insert(values);
        ++tmp;
    }

    LL sum_val = 0LL;
    for(auto v: calculus){
        for(auto item: v){
            // cout << item << ", ";
            sum_val += item;
        }
        // cout << endl;
    }
    out(sum_val);

    return 0;
}