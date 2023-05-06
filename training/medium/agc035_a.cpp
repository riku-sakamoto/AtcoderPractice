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
    int N;
    cin >> N;
    vector<LL> a(N);
    REP(i, N){
        cin >> a[i];
    }

    map<LL, int> counts;
    REP(i, N){
        if(counts.find(a[i]) == counts.end()){
            counts[a[i]] = 1;
        }else{
            counts[a[i]] += 1;
        }
    }
    if(counts.find(0) != counts.end() && counts[0] == N){
        yes();
        return 0;
    }

    if(N % 3 != 0){
        no();
        return 0;
    }

    if(counts.size() == 2){
        if(counts.find(0) == counts.end()){
            no();
            return 0;
        }
        for(auto p: counts){
            if(p.first == 0){
                if(p.second != N / 3){
                    no();
                    return 0;
                }
            }

            if(p.first != 0){
                if(p.second != 2 * N / 3){
                    no();
                    return 0;
                }
            }
        }
        yes();
        return 0;
    }

    if(counts.size() > 3){
        no();
        return 0;
    }

    LL tmp = 0LL;
    for(auto p: counts){
        tmp ^= p.first;
    }
    if(tmp != 0){
        no();
        return 0;
    }

    for(auto p: counts){
        if(p.second != N / 3){
            no();
            return 0;
        }
    }
    yes();
    return 0;
}
