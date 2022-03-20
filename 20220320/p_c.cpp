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


int searchNum(vector<bool>& vecs, int N){
    FOR(i, 1, 2*N+2){
        if(vecs[i] == false){
            return i;
        }
    }
    return 0;
}

int main(){
    int N;
    cin >> N;

    vector<bool> vecs;
    REP(i, 2*N+2){
        vecs.push_back(false);
    }

    int input;
    volatile int k;

    while(true){
        k = searchNum(vecs, N);
        cout << k << endl;
        cout << flush;
        vecs[k] = true;

        cin >> input;
        if (input == 0){
            break;
        }else{
            vecs[input] = true;
        }
    }
    return 0;
}