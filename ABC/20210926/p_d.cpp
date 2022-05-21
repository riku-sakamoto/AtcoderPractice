#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

LL X = 998244353;


int main(){
    int N;
    cin >> N; 
    vector<int> A(N);
    vector<LL> nums(10, 0);
    REP(i, N){
        cin >> A[i];
    }

    nums[A[0]] = 1;

    vector<LL> next_nums(10, 0);

    FOR(i, 1, N){
        REP(j, 10){
            if(nums[j] == 0){continue;}

            int n1 = (j + A[i]) % 10;
            int n2 = (j * A[i]) % 10;
            
            next_nums[n1] = (next_nums[n1] + nums[j]) % X;
            next_nums[n2] = (next_nums[n2] + nums[j]) % X;

        }
        nums = next_nums;
        REP(j, 10){
            next_nums[j] = 0;
        }
    }

    REP(i, 10){
        cout << nums[i] << endl;
    }
    return 0;
    
}