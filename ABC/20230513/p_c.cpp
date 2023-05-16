#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPREV(i,n) for(int i=(n-1);i>=(0);--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
#define BIT(x,i)(((x)>>(i))&1)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}
// template<typename T> T larger_equal(vector<T>& vec, T val){
//     auto ptr = lower_bound(ALL(vec), val);
//     if(ptr == vec.end()){
//         return T(-1);
//     }
//     int idx = ptr - vec.begin();
//     return idx;
// }
// template<typename T> T larger_than(vector<T>& vec, T val){
//     auto ptr = upper_bound(ALL(vec), val);
//     if(ptr == vec.end()){
//         return T(-1);
//     }
//     int idx = ptr - vec.begin();
//     return idx;
// }
// template<typename T> T lower_equal(vector<T>& vec, T val){
//     auto ptr = upper_bound(ALL(vec), val);
//     int idx = ptr - vec.begin() - 1;
//     return idx;
// }
// template<typename T> T lower_than(vector<T>& vec, T val){
//     auto ptr = lower_bound(ALL(vec), val);
//     int idx = ptr - vec.begin() - 1;
//     return idx;
// }
// template<typename T> inline void out_vector(vector<T>& vec){
//     REP(i, vec.size()){cout << vec[i] << " ";}
//     cout << endl;
// }


bool in_atcoder(char c){
    for(auto tmpc: {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'}){
        if( c == tmpc ){
            return true;
        }
    }
    return false;
}

int main(){
    string S;
    string T;
    cin >> S >> T;

    vector<int> used(S.size(), 0);
    map<char, int> char_to_idx;
    REP(i, S.size()){
        char_to_idx[S[i]] += 1;
    }
    REP(i, T.size()){
        if(T[i] == '@'){
            continue;
        }

        char target_char = T[i];
        auto v = char_to_idx[target_char];
        if(v > 0){
            char_to_idx[target_char] -= 1;
            continue;
        }

        if(!in_atcoder(T[i])){
            no(); return 0;
        }
        target_char = '@';
        v = char_to_idx[target_char];
        if(v == 0){
            no(); return 0;
        }
        char_to_idx[target_char] -= 1;
    }

    for(auto p: char_to_idx){
        auto c = p.first;
        auto val = p.second;

        if(val == 0){
            continue;
        }
        if(in_atcoder(c)){
            continue;
        }
        no();
        return 0;
    }
    yes();
    return 0;
}