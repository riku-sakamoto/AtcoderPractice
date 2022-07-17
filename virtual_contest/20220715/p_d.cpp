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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<pair<int, int>> lunches(N);
    REP(i, N){
        int A, B;
        cin >> A >> B;
        lunches[i] = {A, B};
    }

    vector<vector<int>> nums(301, vector<int>(301, 0));
    int x0 = lunches[0].first;
    int y0 = lunches[0].second;
    nums[x0][y0] = 1;
    // cout << "x: " <<  x << ", y:" << y << endl;
    FOR(i, 1, N){
        vector<vector<int>> new_nums(301, vector<int>(301, 0));
        int x = lunches[i].first;
        int y = lunches[i].second;

        // 0にいれる
        new_nums[x][y] = 1;

        REP(a, 301){
            REP(b, 301){
                if(nums[a][b] == 0){continue;}
                // そのまま
                if (new_nums[a][b] == 0){
                    new_nums[a][b] = nums[a][b];
                }else{
                    chmin(new_nums[a][b], nums[a][b]);
                }
                

                int next_a = min({a + x, 300});
                int next_b = min({b + y, 300});
                // cout << a << "," << b << endl;
                int update = 0;
                if(nums[next_a][next_b] == 0){
                    update = 1 + nums[a][b];
                }else{
                    update = min({nums[next_a][next_b], 1 + nums[a][b]});
                }

                if(new_nums[next_a][next_b] == 0){
                    new_nums[next_a][next_b] = update;
                }else{
                    chmin(new_nums[next_a][next_b], update);
                }
                
            }
        }
        nums = new_nums;    
    }

    int ans = -1;
    FOR(a, X, 301){
        FOR(b, Y, 301){
            if(nums[a][b] == 0){continue;}
            // cout << a << ", "<< b << endl;
            if (ans == -1){
                ans = nums[a][b];
            }else{
                chmin(ans, nums[a][b]);
            }
        }
    }

    out(ans);
    return 0;
}