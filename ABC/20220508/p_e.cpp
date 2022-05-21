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

int main(){
    int N, Q;
    cin >> N;
    vector<LL> vecA(N);
    vector<LL> vecB(N);
    REP(i, N){
        cin >> vecA[i];
    }
    REP(i, N){
        cin >> vecB[i];
    }

    vector<int> idxes(N, -1);
    int i = 0;
    int j = 0;
    set<LL> setA;
    while(i < N){
        setA.insert(vecA[i]);

        while(j < N){
            auto itr = setA.find(vecB[j]);
            if(itr != setA.end()){
                ++j;
            }else{
                break;
            }
        }

        idxes[i] = j-1;
        ++i;
    }
    REP(i, N){
        cout << i << ", " << idxes[i] << endl;
    }

    cin >> Q;
    vector<bool> answers(Q, false);
    REP(i, Q){
        int x, y;
        cin >> x >> y;
        int tmp_y = idxes[x-1];

        if(tmp_y >= y-1){
            answers[i] = true;
        }else{
            answers[i] = false;
        }
    }

    REP(i, Q){
        if(answers[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}