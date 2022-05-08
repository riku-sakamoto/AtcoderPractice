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


int getR(int val, int N){
    while(val < 0){
        val += N;
    }

    return val % N;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<LL> A(N);
    REP(i, N){
        cin >> A[i];
    }

    int count_t2 = 0;
    queue<LL> ans;
    REP(i, Q){
        int T, x, y;
        cin >> T >> x >> y;

        if(T == 1){
            int idx_x = getR((x - 1) - count_t2, N);
            int idx_y = getR((y - 1) - count_t2, N);
            // cout << idx_x << ", " << idx_y << endl;
            swap(A[idx_x], A[idx_y]);
            continue;
        }
        if(T == 2){
            count_t2 += 1;
            continue;
        }
        if(T == 3){
            int idx_x = getR((x - 1) - count_t2, N);
            ans.push(A[idx_x]);
        }

    }

    while (!ans.empty())
    {
        LL val = ans.front(); ans.pop();
        cout << val << endl;
    }
    
    return 0;
}