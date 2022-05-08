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
    cin >> N >> Q;
    vector<int> vec;
    map<int, int> pos;
    REP(i, N){
        vec.push_back(i+1);
        pos[i+1] = i;
    }

    REP(i, Q){
        int x;
        cin >> x;
        int target_pos = pos[x];
        if(target_pos != N-1){
            pos[vec[target_pos]] = target_pos+1;
            pos[vec[target_pos+1]] = target_pos;
            swap(vec[target_pos], vec[target_pos+1]);
        }else{
            pos[vec[target_pos]] = target_pos-1;
            pos[vec[target_pos-1]] = target_pos;
            swap(vec[target_pos-1], vec[target_pos]);
        }
    }

    REP(i, N){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}