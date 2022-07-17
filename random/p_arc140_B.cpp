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

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;

    int idx = 0;

    deque<int> que;
    int count_ARC = 0;

    int A_num = 0;
    int C_num = 0;
    bool ARC_find = false;
    FOR(i, 1, N-1){
        if(S[i-1] == 'A' && S[i] == 'R' && S[i+1] == 'C'){
            int l = i - 1;
            int r = i + 1;
            int num_A = 0;
            int num_C = 0;
            while (l - 1 >= 0){
                if(S[l - 1] == 'A'){
                    ++num_A;
                    --l;
                }else{
                    break;
                }
            }
            while(r + 1 < N){
                if(S[r + 1] == 'C'){
                    ++num_C;
                    ++r;
                }else{
                    break;
                }
            }

            int num = min({num_A, num_C}) + 1; 
            if(num == 1){
                que.push_back(num);
            }else{
                que.push_front(num);
            }
        }
    }

    int ans = 0;
    int i = 0;
    while(que.size() != 0){
        // cout << que.front() << ", " << que.back() << endl;

        if(i % 2 == 0){
            int val = que.front(); que.pop_front();
            ans += 1;
            if(val == 1){
                ++i;
                continue;
            }
            if(val - 1 == 1){
                que.push_back(val - 1);
            }else{
                que.push_front(val - 1);
            }
        }else{
            int val = que.back(); que.pop_back();
            ans += 1;
        }
        ++i;
    }


    out(ans);

    return 0;
}