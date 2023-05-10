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
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> cars(N);
    REP(i, N){
        cars[i] = {-1, -1};
    }

    vector<deque<int>> answers;
    REP(i, Q){
        int idx, x, y;
        cin >> idx;
        if(idx == 1){
            cin >> x >> y;
            --x;
            --y;
            cars[x].second = y;
            cars[y].first = x;
            continue;
        }
        if(idx == 2){
            cin >> x >> y;
            --x;
            --y;
            cars[x].second = -1;
            cars[y].first = -1;
            continue;
        }
        if(idx == 3){
            cin >> x;
            deque<int> que;
            que.push_back(x);
            --x;
            int parent = cars[x].first;;
            while(true){
                if(parent == -1){
                    break;
                }
                que.push_front(parent + 1);
                parent = cars[parent].first;
            }

            int child = cars[x].second;
            while(true){
                if(child == -1){
                    break;
                }
                que.push_back(child + 1);
                child = cars[child].second;
            }

            answers.push_back(que);
        }

    }

    for(auto que: answers){
        int n = que.size();
        cout << n << " ";
        while(!que.empty()){
            auto val = que.front();que.pop_front();
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}