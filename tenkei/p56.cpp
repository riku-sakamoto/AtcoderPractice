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

void update(vector<LL> &costs, vector<string> &answers, int val, string ans, int num){
    if(val < costs.size()){
        costs[val] += 1;
        answers[val] = ans;
    }
}

int main(){
    int N, S;
    cin >> N >> S;

    vector<LL> A(N);
    vector<LL> B(N);
    REP(i, N){
        cin >> A[i] >> B[i];
    }

    vector<LL> costs(S+1, 0);
    vector<string> answers(S+1, "");
    update(costs, answers, A[0], "A", 0);
    update(costs, answers, B[0], "B", 0);

    FOR(i, 1, N){
        vector<LL> _costs(S+1, 0);
        vector<string> _answers(S+1, "");

        REP(j, S+1){
            if(costs[j] == 0) continue;
            update(_costs, _answers, j + A[i], answers[j] + "A", i);
            update(_costs, _answers, j + B[i], answers[j] + "B", i);
        }
        costs = _costs;
        answers = _answers;
    }

    if(answers[S].length() != N){
        cout << "Impossible" << endl;
    }else{
        cout << answers[S] << endl;
    }
    return 0;

}