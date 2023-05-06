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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> nums(N, 0);
    REP(i, N){
        if(i == 0){
            nums[i] = 0;
            continue;
        }

        if(S[i] == 'C' && S[i-1] == 'A'){
            nums[i] = 1 + nums[i - 1];
        }else{
            nums[i] = nums[i - 1];
        }
    }

    queue<int> answers;
    REP(i, Q){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int val1 = nums[r];
        int val2 = nums[l];
        int ans = val1 - val2;

        answers.push(ans);
    }

    while(!answers.empty()){
        int val = answers.front(); answers.pop();
        cout << val << endl;
    }
    return 0;
}