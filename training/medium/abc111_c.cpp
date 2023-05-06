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
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, n)cin>>v[i];

    map<int, int> evens;
    map<int, int> odds;
    REP(i, n){
        if(i % 2 == 0){
            if(odds.find(v[i]) != odds.end()){
                odds[v[i]] += 1;
            }else{
                odds[v[i]] = 1;
            }
        }else{
            if(evens.find(v[i]) != evens.end()){
                evens[v[i]] += 1;
            }else{
                evens[v[i]] = 1;
            }
        }
    }
    // counts, value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> even_que;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> odd_que;
    even_que.push({n / 2, -1});
    odd_que.push({n / 2, -1});

    for(auto v: evens){
        even_que.push({n / 2 - v.second, v.first});
    }
    for(auto v: odds){
        odd_que.push({n / 2 - v.second, v.first});
    }
    int ans = 0;
    auto even_item = even_que.top();even_que.pop();
    auto odd_item = odd_que.top();odd_que.pop();

    if(even_item.second != odd_item.second){
        ans = even_item.first + odd_item.first;
        out(ans);
        return 0;
    }

    // equal
    auto s_even_item = even_que.top();
    auto s_odd_item = odd_que.top();
    ans = even_item.first + s_odd_item.first;

    int tmp_ans = odd_item.first + s_even_item.first;
    chmin(ans, tmp_ans);

    out(ans);
    return 0;
}