#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) x.begin(),x.end()
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> Pij(H, vector<int>(W, 0));

    REP(i, H){
        REP(j, W){
            cin >> Pij[i][j];
        }
    }
    
    priority_queue<int> ansque;

    REP(i0, 1 << H){
        vector<int> rows;
        REP(j, H){
            if(i0 & ( 1 << j ) ){
                rows.push_back(j);
            }
        }

        if(rows.size() == 0)continue;

        map<int, int> tmpAns;
        REP(j, W){
            bool isSame = true;
            int val = Pij[rows[0]][j];
            for(int i: rows){
                if(val != Pij[i][j]){
                    isSame = false;
                    break;
                }
            }
            if(isSame){
                if(tmpAns.count(val) == 0){
                    tmpAns[val] = 1;
                }else{
                    tmpAns[val] += 1;
                }
            }
        }

        int max_key = 0; 
        int tmp_max = 0;
        for(auto itr=tmpAns.begin(); itr!=tmpAns.end(); ++itr){
            if(tmp_max < itr->second){
                chmax(tmp_max, itr->second);
                max_key = itr->first;
            }
        }

        int points = rows.size() * tmpAns[max_key];
        ansque.push(points);
    }


    int ans = ansque.top();
    cout << ans << endl;
    return 0;
}