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
    string S;
    cin >> S;

    int N = (int)S.size() + 1;
    vector<int> diffs;

    int delta = 0;
    char pre = S[0];
    REP(i, N-1){
        auto c = S[i];
        if(pre != c){
            diffs.push_back(delta);
            delta = 0;
        }

        if(c == '<'){
            delta += 1;
        }else{
            delta -= 1;
        }
        pre = c;
    }
    diffs.push_back(delta);
    // for(auto diff: diffs){
    //     out(diff);
    // }

    int n = (int)diffs.size();
    vector<int> points;
    if (diffs[0] > 0){
        points.push_back(0);
    }else{
        points.push_back(abs(diffs[0]));
    }

    REP(i, n-1){
        int diff = diffs[i];
        int diff_next = diffs[i + 1];
        if(diff < 0){
            points.push_back(0);
        }else{
            points.push_back(max({diff, abs(diff_next)}));
        }
    }

    vector<int> nums(N);
    nums[0] = points[0];
    int k = 1;
    FOR(i, 1, N){
        if(i != N-1 && S[i-1] != S[i]){
            nums[i] = points[k];
            ++k;
        }else{
            if(S[i-1] == '<'){
                nums[i] = nums[i-1] + 1;
            }else{
                nums[i] = nums[i-1] - 1;
            }
        }
    }

    int sums = 0;
    REP(i, N){
        sums += nums[i];
    }

    out(sums);
    return 0;
}