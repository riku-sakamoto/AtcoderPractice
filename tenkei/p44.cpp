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

void userSwap(vector<LL> &vec, int i, int j, int n, int T){
    int i_ = (i - T) % n;
    int j_ = (j - T) % n;

    if (i_ < 0) i_ += n;
    if (j_ < 0) j_ += n;

    swap(vec[i_], vec[j_]);
}

LL getElem(vector<LL> &vec, int i, int n, int T){
    int i_ = (i - T) % n;
    if (i_ < 0) i_ += n;
    return vec[i_];
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<LL> A(N);
    REP(i, N)cin >> A[i];

    queue<LL> answers;
    int T = 0;
    REP(i, Q){
        int ti;
        cin >> ti;

        int x, y;
        cin >> x >> y;
        if(ti == 1){
            userSwap(A, x-1, y-1, N, T);
        }

        if(ti == 2){
            T += 1;
        }

        if(ti == 3){
            answers.push(getElem(A, x-1, N, T));
        }

    }

    while(!answers.empty()){
        int ans = answers.front(); answers.pop();
        cout << ans << endl;
    }

    return 0;
    
}