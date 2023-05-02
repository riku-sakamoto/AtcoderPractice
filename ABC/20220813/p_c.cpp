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

int h1, w1;
int h2, w2;

vector<set<int>> exhausticSearch(int n){
    vector<set<int>> deletes;
    // ｎまでの全探索
    REP(i, 1LL<<n){
        set<int> delete_nums;
        REP(j, n){
            if((i & (1LL << j)) != 0){
                delete_nums.insert(j);
            }
        }
        deletes.push_back(delete_nums);
    }
    return deletes;
}

bool check(vector<vector<LL>>& A, vector<vector<LL>>& B, set<int> delete_rows, set<int> delete_cols){
    int skip_row = 0;
    REP(i, h1){
        int skip_col = 0;
        if (delete_rows.find(i) != delete_rows.end()){
            skip_row += 1;
            continue;
        }
        REP(j, w1){
            if(delete_cols.find(j) != delete_cols.end()){
                skip_col += 1;
                continue;
            }
            int b_i = i - skip_row;
            int b_j = j - skip_col;

            if(A[i][j] != B[b_i][b_j]){
                return false;
            }
        }
    }
    return true;

}



int main(){
    cin >> h1 >> w1;
    vector<vector<LL>> A(h1, vector<LL>(w1, 0LL));
    REP(i, h1){
        REP(j, w1){
            cin >> A[i][j];
        }
    }
    cin >> h2 >> w2;
    vector<vector<LL>> B(h2, vector<LL>(w2, 0LL));
    REP(i, h2){
        REP(j, w2){
            cin >> B[i][j];
        }
    }

    auto delte_rows = exhausticSearch(h1);
    auto delte_cols = exhausticSearch(w1);

    for(auto d_rows: delte_rows){
        for(auto d_cols: delte_cols){
            int d_r_l = d_rows.size();
            int d_c_l = d_cols.size();
            if (h1 - d_r_l != h2 || w1 - d_c_l != w2){
                continue;
            }

            bool ck = check(A, B, d_rows, d_cols);
            if(ck == true){
                out("Yes");
                return 0;
            }
        }
    }
    out("No");
    return 0;
}