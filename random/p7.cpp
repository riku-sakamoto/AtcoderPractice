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

int search(int li, int ri, vector<LL>& nums, LL val){
    if (ri - li <= 1){
        return li;
    }

    int i = (li + ri) / 2;
    if(nums[i] == val) return i;
    if(nums[i] > val) ri = i;
    else li = i;
    
    return search(li, ri, nums, val);
}

int main(){
    int N, Q;
    cin >> N;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];
    cin >> Q;
    vector<LL> B(Q);
    REP(i, Q)cin >> B[i];

    sort(ALL(A));
    queue<LL> ans;
    REP(i, Q){
        if(A[0] > B[i]){
            ans.push(abs(A[0] - B[i])); continue;
        }
        if(A[N-1] < B[i]){
            ans.push(abs(B[i] - A[N-1])); continue;
        }

        int k = search(0, N-1, A, B[i]);
        ans.push(min({abs(A[k] - B[i]), abs(A[k+1] - B[i])}));
    }


    while (!ans.empty())
    {
        LL v = ans.front(); ans.pop();
        cout << v << endl;
    }
    

    return 0;
}