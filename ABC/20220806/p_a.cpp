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
    vector<int> nums(5);
    REP(i, 5)cin >> nums[i];

    map<int, int> num_dict;
    REP(i, 5){
        int num = nums[i];
        if(num_dict.find(num) == num_dict.end()){
            num_dict[num] = 1;
        }else{
            num_dict[num] += 1;
        }
    }

    if(num_dict.size() != 2){
        no();
        return 0;
    }

    for(auto p: num_dict){
        if(p.second == 3 || p.second == 2){
            continue;
        }else{
            no();
            return 0;
        }
    }
    yes();
    return 0;
}