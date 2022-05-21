#define _GLIBCXX_DEBUG
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
template<typename T>
void remove(vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
    int Q;
    cin >> Q;
    priority_queue<LL, vector<LL>, greater<LL>> pque;
    queue<LL> que;
    queue<LL> answer;

    int q;
    REP(i,Q){
        cin >> q;
        if(q == 1){
            LL x;
            cin >> x;
            que.push(x);
        } else if(q == 2){
            LL y;
            if(pque.empty()){
                y = que.front();que.pop();
            }else{
                y = pque.top();pque.pop();
            }
            answer.push(y);
        }else{
            while(!que.empty()){
                LL z = que.front();que.pop();
                pque.push(z);
            }
        }
    }

    while (!answer.empty())
    {
        LL y = answer.front();answer.pop();
        cout << y << endl;
    }

    return 0;
    
    
}