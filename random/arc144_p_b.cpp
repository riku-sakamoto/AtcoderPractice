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

LL a, b;
bool enableManipulate(vector<LL>& A, LL val){
    LL count_a = 0;
    LL count_b = 0;
    for(LL ai : A){
        if(val - ai > 0){
            count_a += (val - ai) / a;
            if ((val - ai) % a != 0){
                count_a += 1;
            }
        }else{
            count_b += (ai - val) / b;
            if ((ai - val) / b == 0)continue;

        }
    }
    
    return count_a <= count_b;
}


int main(){
    int N;
    cin >> N >> a >> b;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];
    sort(ALL(A));
    LL left = A[0];
    LL right = A[N-1];

    while(right - left > 1){
        LL mid = (left + right) / 2;
        bool possible = enableManipulate(A, mid);
        if (possible){
            left = mid;
        }else{
            right = mid;
        }
    }

    out(left);

    return 0;
}