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

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    REP(i, N){
        REP(j, N){
            cin >> A[i][j];
        }
    }
    int M;
    cin >> M;
    vector<vector<int>> B(N);
    REP(i, M){
        int X, Y;
        cin >> X >> Y;
        B[X-1].push_back(Y-1);
        B[Y-1].push_back(X-1);
    }

    REP(i, N){
        sort(ALL(B[i]));
    }

    vector<int> lines;
    REP(i, N)lines.push_back(i);
    vector<int> answers;
    do{
        bool isSuccess = true;
        int ans = A[lines[0]][0];
        // print(lines);
        FOR(j, 1, N){
            int num = lines[j];
            int num_pre = lines[j-1];

            if(binary_search(ALL(B[num]),num_pre) == true){
                // cout << "b_search: " << num << num_next << endl;
                isSuccess = false;
                break;
            }else{
                ans += A[num][j];
            }
        }
        if(isSuccess == true){
            // print(lines);
            // cout << ans << endl;
            answers.push_back(ans);
        }
    }while(std::next_permutation(lines.begin(), lines.end()));
    
    if(answers.size() == 0){
        cout << -1 << endl;
    }else{
        cout << *min_element(ALL(answers)) << endl;
    }

    return 0;
}