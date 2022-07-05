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

char slot_char(char mozi, int num){
    int all = 'z' - 'a' + 1;
    int new_num = num % all;
    int num_to_a = 'z' - mozi + 1;
    if(new_num >= num_to_a){
        new_num = new_num - num_to_a;
        mozi = 'a';
    }
    char target = mozi + new_num;
    return target;
}

int main(){
    string S;
    cin >> S;
    int n_S = (int)S.size();
    LL K;
    cin >> K;

    vector<int> numToA;
    REP(i, S.size()){
        int k = 'z' - S[i] + 1;
        numToA.push_back(k);
    }

    REP(i, n_S){
        if(S[i] == 'a'){
            continue;
        }
        if(numToA[i] <= K){
            K -= numToA[i];
            S[i] = 'a';
            numToA[i] = 'z' - S[i] + 1;
        }
    }

    K = K % 26LL;
    S[n_S-1] = slot_char(S[n_S-1], K);

    out(S);
    // out(slot_char('a', 25));
    return 0;
}