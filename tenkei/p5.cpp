#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPLL(i,n) for(LL i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const LL target = 1E9+7;
LL N;
int B, K;

vector<vector<LL>> power_matrix(vector<vector<LL>> matA, LL times){
    vector<vector<LL>> mat = matA;
    
    REPLL(k, times - 1){
        vector<vector<LL>> _mat(B, vector<LL>(B, 0));
        REP(i, B){
            REP(j, B){
                LL val = 0;
                REP(k, B){
                    val += (mat[i][k] * matA[k][j]) % target;
                    // cout << val << " ";
                }
                // cout << endl;
                _mat[i][j] = val;
            }
        }
        mat = _mat;
    }
    return mat;
}


vector<vector<LL>> mat_mul(vector<vector<LL>> matA, vector<vector<LL>> matB){
    vector<vector<LL>> mat(B, vector<LL>(B, 0));

    REP(i, B){
        REP(j, B){
            LL val = 0;
            REP(k, B){
                val = (val + ((matA[i][k] % target) * (matB[k][j] % target)) % target) % target;
                // cout << val << " ";
            }
            // cout << endl;
            mat[i][j] = val;
        }
    }
    return mat;
}

vector<vector<LL>> mat_pow(vector<vector<LL>> matA, LL n){
    vector<vector<LL>> mat(B, vector<LL>(B, 0));
    REP(i, B){
        REP(j, B){
            if(i == j){
                mat[i][j] = 1;
            }
        }
    }
    
    while (n > 0){
        if (n & 1){
            mat = mat_mul(mat, matA);
        }

        matA = mat_mul(matA, matA);
        n = (n >> 1);
        // cout << n << endl;
    }

    return mat;
}




int main(){

    cin >> N >> B >> K;
    vector<int> ci(K);
    vector<int> rvec(B, 0);
    vector<vector<LL>> matA(B, vector<LL>(B, 0));
    REP(i,K)cin >> ci[i];
    LL ans = 0;

    // initialize mat
    REP(j, B){
        REP(k, K){
            int r = (10 * j + ci[k]) % B;
            matA[r][j] += 1;
        }
    }

    REP(ik, K){
        int r = ci[ik] % B;
        rvec[r] += 1;
    }

    // vector<vector<LL>> mat = power_matrix(matA, N - 1);
    vector<vector<LL>> mat = mat_pow(matA, N-1);
    // REP(i, B){
    //     REP(j, B){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if( N == 1){
        ans = rvec[0];
        cout << ans << endl;
        return 0;
    }

    REP(j, B){
        ans = (ans + (mat[0][j] * rvec[j]) % target) %target;
    }
    cout << ans << endl;
    return 0;
    
}