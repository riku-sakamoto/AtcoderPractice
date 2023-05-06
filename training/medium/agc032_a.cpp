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
    vector<int> vec(N);
    REP(i, N){
        cin >> vec[i];
    }

    deque<int> que;
    while(true){
        if(vec.size() == 0){
            break;
        }
        int target = -1;
        REP(i, vec.size()){
            if (vec[i] > i + 1){
                cout << -1 << endl;
                return 0;
            }

            if(vec[i] == i + 1){
                target = i;
            }
        }

        if(target == -1){
            cout << -1 << endl;
            return 0;
        }

        que.push_front(vec[target]);
        vec.erase(vec.begin() + target);
    }

    while(!que.empty()){
        int v = que.front(); que.pop_front();
        cout << v << endl;
    }

    return 0;
}