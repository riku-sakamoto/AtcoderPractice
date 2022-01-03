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


bool janken(char v1, char v2){
    if(v1 == 'G' && v2 == 'C'){
        return true;
    }
    if(v1 == 'P' && v2 == 'G'){
        return true;
    }
    if(v1 == 'C' && v2 == 'P'){
        return true;
    }

    return false;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<char>> Aij = vector<vector<char>>(2*N, vector<char>(M, '0'));

    REP(i, 2*N){
        REP(j, M){
            cin >> Aij[i][j];
        }
    }

    auto comp = [](pair<int, int> l, pair<int, int> r){
        if(l.first == r.first){
            return l.second > r.second;
        }else{
            return l.first < r.first;
        }
    };    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> nums(comp); 
    
    // nums.push(pair<int, int>(0, 0));
    // nums.push(pair<int, int>(0, 1));
    // nums.push(pair<int, int>(1, 2));
    // nums.push(pair<int, int>(2, 3));
    // nums.push(pair<int, int>(2, 4));
    REP(i, 2*N){
        nums.push(pair<int, int>(0, i));
    }

    int j =0;
    while(j < M){
        priority_queue<pair<int, int>> new_nums; 
        REP(k, N){
            pair<int, int> p1 = nums.top();
            nums.pop();
            pair<int, int> p2 = nums.top();
            nums.pop();
            char p1_c = Aij[p1.second][j];
            char p2_c = Aij[p2.second][j];

            bool isp1Win = janken(p1_c, p2_c);
            bool isp2Win = janken(p2_c, p1_c);

            if(isp1Win){
                p1.first += 1;
            }
            if(isp2Win){
                p2.first += 1;
            }

            new_nums.push(p1);
            new_nums.push(p2);
        }

        REP(i, 2*N){
            nums.push(new_nums.top());
            new_nums.pop();
        }
        
        j++;
    }

    while(nums.size()!= 0){
        pair<int, int> p1 = nums.top();
        nums.pop();
        cout << p1.second + 1 << endl;
    }

    return 0;
}