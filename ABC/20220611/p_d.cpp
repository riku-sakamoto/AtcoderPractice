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
    int N, Q;
    cin >> N >> Q;
    vector<LL> A(N);
    REP(i, N)cin>>A[i];

    sort(ALL(A));

    vector<LL> sums(N);
    LL tmp_sum = 0;
    REP(i, N){
        tmp_sum += A[i];
        sums[i] = tmp_sum;
    }

    queue<LL> answers;
    REP(i, Q){
        LL x;
        cin >> x;

        auto itr = lower_bound(ALL(A), x);
        if(itr == A.begin()){
            LL val_sum = sums[N-1];
            answers.push(val_sum - x * N);
            continue;
        }

        if(itr == A.end()){
            LL val_sum = sums[N-1];
            answers.push(x * N - val_sum);
            continue;
        }

        int idx = itr - A.begin();
        int num_large = (N - idx);
        int num_small = idx;

        LL val_sum_large_part = sums[N-1] - sums[idx-1];
        LL val_sum_small_part = sums[idx-1];
        // cout << idx << ", " << A[idx] << endl;
        // cout << num_large << ", " << num_small << endl;
        // cout << val_sum_large_part << ", " << val_sum_small_part << endl;


        answers.push(val_sum_large_part - num_large * x \
                    + num_small * x - val_sum_small_part);
    }

    while(!answers.empty()){
        LL val = answers.front(); answers.pop();
        cout << val << endl;
    }
    return 0;
}