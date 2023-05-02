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
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    REP(i, N)cin >> P[i];

    // 現在表向きのカード
    set<int> nums;
    // numの直下に表向きに置かれたカード
    vector<int> fronts(N+1, 0);
    // 下から数えて何枚目か
    vector<int> counts(N+1, 0);
    vector<int> answers(N+1, -1);

    REP(i, N){
        int val = P[i];
        auto itr = nums.lower_bound(val);
        if(itr == nums.end()){
            counts[val] = 1;
            nums.insert(val);
        }else{
            fronts[val] = *itr;
            counts[val] = counts[*itr] + 1;
            nums.erase(itr);
            nums.insert(val);
        }

        if(counts[val] == K){
            nums.erase(val);
            REP(j, K){
                answers[val] = (i + 1);
                val = fronts[val];
            }
        }
    }

    FOR(i, 1, N+1){
        out(answers[i]);
    }

   return 0;
}