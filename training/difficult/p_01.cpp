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


// ランレングス圧縮
void rle_compress(string s, vector<pair<char, int>> &vec){
    int count = 0;
    char pre;
    for(int i = 0; i < (int)s.size(); ++i){
        if(i == 0){
            pre = s[i];
            count += 1;
            continue;
        }

        if(pre == s[i]){
            ++count;
        }else{
            vec.push_back({pre, count});
            pre = s[i];
            count = 1;
        }
    }
    vec.push_back({pre, count});
    return;
}


int main(){
    string S;
    cin >> S;

    int N = S.size();
    vector<pair<char, int>> rles;
    rle_compress(S, rles);

    vector<int> target_R_pos(N);
    vector<int> length(N);
    int idx = 0;
    for(auto p: rles){
        if(p.first == 'R'){
            REP(i, p.second){
                length[idx] = p.second - i - 1;
                target_R_pos[idx] = idx + p.second - i - 1;
                idx++;
            }
        }else{
            REP(i, p.second){
                target_R_pos[idx] = idx - (i + 1);
                length[idx] = i + 1;
                idx++;
            }
        }
    }

    // REP(i, N){
    //     cout << length[i] << ", " << target_R_pos[i] << endl;
    // }
    vector<int> answers(N, 0);
    REP(i, N){
        int l = length[i];
        int r_pos = target_R_pos[i];
        if(l % 2 == 0){
            answers[r_pos] += 1;
        }else{
            answers[r_pos + 1] += 1;
        }
        
    }

    REP(i, N){
        cout << answers[i] << " ";
    }
    cout << endl;
    return 0;
}