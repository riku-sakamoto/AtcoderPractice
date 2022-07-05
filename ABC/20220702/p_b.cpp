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
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
template <class T> inline void out(T a){cout << a << endl;}



pair<int, int> calc_next_pos(pair<int, int> pos, string dir, int N){
    int next_i;
    int next_j;
    if(dir == "up"){
        next_i = pos.first - 1;
        next_j = pos.second;
    }else if(dir == "down"){
        next_i = pos.first + 1;
        next_j = pos.second;
    }else if(dir == "right"){
        next_i = pos.first;
        next_j = pos.second + 1;
    }else if(dir == "upright"){
        next_i = pos.first - 1;
        next_j = pos.second + 1;
    }else if(dir == "upleft"){
        next_i = pos.first - 1;
        next_j = pos.second - 1;
    }else if(dir == "downright"){
        next_i = pos.first + 1;
        next_j = pos.second + 1;
    }else if(dir == "downleft"){
        next_i = pos.first + 1;
        next_j = pos.second - 1;
    }else{
        next_i = pos.first;
        next_j = pos.second - 1;
    }

    if(next_i < 0){
        next_i += N;
    }
    if(next_i >= N){
        next_i -= N;
    }
    if(next_j >= N){
        next_j -= N;
    }
    if(next_j < 0){
        next_j += N;
    }

    return {next_i, next_j};
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    REP(i, N){
        string S;
        cin >> S;
        REP(j, S.size()){
            int val = S[j] - '0';
            A[i][j] = val;
        }
    }

    vector<string> dirs = {"up", "down", "left", "right", "upleft", "upright", "downleft", "downright"};
    vector<string> answers;
    REP(i, N){
        REP(j, N){
            for(auto dir: dirs){
                pair<int, int> pos = {i, j};
                string tmpS = "";
                REP(_, N){
                    char c = '0' + A[pos.first][pos.second];
                    tmpS += c;

                    pair<int, int> next_pos = calc_next_pos(pos, dir, N);
                    int next_val = A[next_pos.first][next_pos.second];
                    pos = next_pos;
                    
                    answers.push_back(tmpS);

                }
            }

        }
    }

    sort(ALL(answers));
    int l = answers.size();
    cout << answers[l-1] << endl;
    return 0;
}