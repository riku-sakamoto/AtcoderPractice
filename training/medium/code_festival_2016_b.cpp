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

LL N;

LL bs(LL start, LL end){
    if(end - start <= 1){
        return end;
    }
    LL mid = (end + start) / 2;
    
    LL tmp_sum = (mid * (mid - 1)) / 2 + mid;
    if(tmp_sum >= N){
        end = mid;
    }else{
        start = mid;
    }
    return bs(start, end);
}

int main(){
    cin >> N;

    set<LL> answers;
    LL K = bs(1LL, N);

    answers.insert(K);
    LL left = N - K;
    LL tmp_sum = 0LL;
    REP(i, K){
        if(i == 0){
            continue;
        }
        if(tmp_sum == left){break;}
        tmp_sum += (LL)i;
        answers.insert(i);

        if(tmp_sum > left){
            LL r = tmp_sum - left;
            answers.erase(r);
            break;
        }
    }

    for(auto v: answers){
        out(v);
    }

    return 0;
}