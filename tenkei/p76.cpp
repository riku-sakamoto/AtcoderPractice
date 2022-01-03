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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int forward(int i, int N){
    if(i == N-1){
        return 0;
    }
    return i + 1;
}

int main(){
    int N;
    cin >> N;

    vector<LL> Ai(N);
    REP(i, N){
        cin >> Ai[i];
    }


    LL sum_A = 0;
    REP(i, N){
        sum_A += Ai[i];
    }
    bool ans = false;

    int start = 0;
    LL tmp = 0;

    int i = 0;
    set<int> starts;
    starts.insert(start);

    while(true){
        tmp += Ai[i];

        if(10 * tmp > sum_A){
            while(10 * tmp > sum_A){
                tmp -= Ai[start];
                start = forward(start, N);
            }

            if(starts.find(start) != starts.end()){
                break;
            }
            starts.insert(start);
        }
        
        if(sum_A == 10 * tmp){
            ans = true;
            break;
        }

        i = forward(i, N);
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    return 0;
    
}