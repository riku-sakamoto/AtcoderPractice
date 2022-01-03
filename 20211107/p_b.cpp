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


    bool IsAllSame(vector<LL>& A, vector<LL>& B){
        if(A.size() != B.size()){return false;}

        // REP(i, A.size()){
        //     if(A[i] != B[i]){
        //         return false;
        //     }
        // }
        return A == B;

        // return true;
    }

    int main(){
        int N;
        cin >> N;
        vector<int> Li(N);
        vector<vector<LL>> Aij(N);
        REP(i, N){
            cin >> Li[i];
            REP(j, Li[i]){
                LL a;
                cin >> a;
                Aij[i].push_back(a);
            }
        }

        int ans = 1;
        sort(ALL(Aij));

        FOR(i, 1, N){
            vector<LL> target = Aij[i];
            if(IsAllSame(target, Aij[i-1]) == false){
                ans += 1;
            }
        }
        cout << ans << endl;

        // REP(i, N){
            
        //     REP(j, Aij[i].size()){
        //         cout << Aij[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // vector<vector<LL>> Bij;
        // Bij.push_back(Aij[0]);
        // FOR(i, 1, N){
        //     vector<LL> target = Aij[i];

        //     bool isSame = false;

        //     REP(k, Bij.size()){
        //         vector<LL> bi = Bij[k];
        //         bool isSameTmp = IsAllSame(target, bi);
        //         if(isSameTmp == true){
        //             isSame = true;
        //             break;
        //         }
        //     }

        //     if(isSame == false){
        //         Bij.push_back(target);
        //     }
        // }
        
        // cout << Bij.size() << endl;
        return 0;
    }