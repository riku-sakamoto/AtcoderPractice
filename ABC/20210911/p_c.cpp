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

int N;

int getMinRow(vector<vector<char>> &Gmap){
    REP(i, N){
        REP(j, N){
            if(Gmap[i][j] == '#'){
                return i;
            }
        }
    }
    return N-1;
}

int getMinCol(vector<vector<char>> &Gmap){
    REP(j, N){
        REP(i, N){
            if(Gmap[i][j] == '#'){
                return j;
            }
        }
    }
    return N-1;
}

int getMaxRow(vector<vector<char>>& Gmap){
    for(int i=N-1; i>=0; i--){
        REP(j, N){
            if(Gmap[i][j] == '#'){
                return i;
            }
        }
    }
    return 0;
}


int getMaxCol(vector<vector<char>>& Gmap){
    for(int j=N-1; j>=0; j--){
        REP(i, N){
            if(Gmap[i][j] == '#'){
                return j;
            }
        }
    }
    return 0;
}

vector<int> getRangeVector(int min, int max){
    vector<int> vec;
    FOR(i, min, max+1){
        vec.push_back(i);
    }
    return vec;
}


bool CheckIsSameGraph(vector<vector<char>>& S, vector<vector<char>>& T, vector<int>& S_cols, vector<int>& S_rows, vector<int>& T_cols, vector<int>& T_rows, int type){
    if(type==0){
        // 0度回転
        if(S_rows.size() == T_rows.size() && S_cols.size() == T_cols.size()){}
        else{return false;}

        REP(i, T_rows.size()){
            REP(j, T_cols.size()){
                int i_S = S_rows[i];
                int j_S = S_cols[j];
                int i_T = T_rows[i];
                int j_T = T_cols[j];

                if(S[i_S][j_S]!= T[i_T][j_T]){
                    return false;
                }
            }
        }
    } else if (type==1){
        // 90度回転
        if(S_rows.size() == T_cols.size() && S_cols.size() == T_rows.size()){}
        else{return false;}
        REP(i, T_rows.size()){
            REP(j, T_cols.size()){
                int i_S = S_rows[j];
                int j_S = S_cols[(int)S_cols.size() - i - 1];
                int i_T = T_rows[i];
                int j_T = T_cols[j];

                if(S[i_S][j_S] != T[i_T][j_T]){
                    return false;
                }
            }
        }
    } else if (type==2){
        //180度回転
        if(S_rows.size() == T_rows.size() && S_cols.size() == T_cols.size()){}
        else{return false;}

        REP(i, T_rows.size()){
            REP(j, T_cols.size()){
                int i_S = S_rows[S_rows.size() - i - 1];
                int j_S = S_cols[T_cols.size() - j - 1];
                int i_T = T_rows[i];
                int j_T = T_cols[j];

                if(S[i_S][j_S]!= T[i_T][j_T]){
                    return false;
                }
            }
        }
    }else{
        // 270度回転
        if(S_rows.size() == T_cols.size() && S_cols.size() == T_rows.size()){}
        else{return false;}

        REP(i, T_rows.size()){
            REP(j, T_cols.size()){
                int i_S = S_rows[S_rows.size() - j - 1];
                int j_S = S_cols[i];
                int i_T = T_rows[i];
                int j_T = T_cols[j];

                if(S[i_S][j_S] != T[i_T][j_T]){
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main(){
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(N, vector<char>(N));
    
    REP(i, N){
        REP(j, N){
            cin >> S[i][j];
        }
    }

    REP(i, N){
        REP(j, N){
            cin >> T[i][j];
        }
    }


    int minS_row = getMinRow(S);
    int maxS_row = getMaxRow(S);
    int minS_col = getMinCol(S);
    int maxS_col = getMaxCol(S);
    // T
    int minT_row = getMinRow(T);
    int maxT_row = getMaxRow(T);
    int minT_col = getMinCol(T);
    int maxT_col = getMaxCol(T);
    
    vector<int> S_cols = getRangeVector(minS_col, maxS_col);
    vector<int> S_rows = getRangeVector(minS_row, maxS_row);
    vector<int> T_cols = getRangeVector(minT_col, maxT_col);
    vector<int> T_rows = getRangeVector(minT_row, maxT_row);

    bool ok = false;
    ok = ok || CheckIsSameGraph(S, T, S_cols, S_rows, T_cols, T_rows, 0);
    ok = ok || CheckIsSameGraph(S, T, S_cols, S_rows, T_cols, T_rows, 1);
    ok = ok || CheckIsSameGraph(S, T, S_cols, S_rows, T_cols, T_rows, 2);
    ok = ok || CheckIsSameGraph(S, T, S_cols, S_rows, T_cols, T_rows, 3);


    
    // REP(i, T_rows.size()){
    //     REP(j, T_cols.size()){
    //         // int i_S = S_rows[S_rows.size() - j - 1];
    //         // int j_S = S_cols[i];
    //         // int i_S = S_rows[j];
    //         // int j_S = S_cols[(int)S_cols.size() - i - 1];
    //         int i_T = T_rows[i];
    //         int j_T = T_cols[j];

    //         // cout << S[i_S][j_S];
    //         cout << T[i_T][j_T];
    //     }
    //     cout << endl;
    // }

    // REP(i, T_rows.size()){
    //     REP(j, T_cols.size()){
    //         // int i_S = S_rows[S_rows.size() - j - 1];
    //         // int j_S = S_cols[i];
    //         // int i_S = S_rows[S_rows.size() - i - 1];
    //         // int j_S = S_cols[T_cols.size() - j - 1];
    //         int i_S = S_rows[j];
    //         int j_S = S_cols[(int)S_cols.size() - i - 1];
    //         // int i_T = T_rows[i];
    //         // int j_T = T_cols[j];

    //         cout << S[i_S][j_S];
    //         // cout << T[i_T][j_T];
    //     }
    //     cout << endl;
    // }


    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;

}