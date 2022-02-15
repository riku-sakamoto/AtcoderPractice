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

int N;


bool checkakko(int num){
    int check = 0;
    for(int i=N-1; i>=0; --i){
        if((num & (1 << i)) == 0){
            check +=1;
        }else{
            check -=1;
        }
        if(check < 0){
            return false;
        }
    }

    if(check != 0) return false;
    return true;

}

string convertKakko(int num){
    string ans = "";
    for(int i=N-1; i>=0; --i){
        if((num & (1 << i)) == 0){
            ans += "(";
        }else{
            ans += ")";
        }
    }

    return ans;

}

int main(){
    cin >> N;

    vector<int> ans;
    for(int k =0; k < 1<<N; ++k){
        // cout << "k: " << k << endl;
        bool isOk = checkakko(k);
        // cout << "isOk: " << isOk << endl;
        if(isOk) ans.push_back(k);
    }

    REP(i, ans.size()){
        string ansStr = convertKakko(ans[i]);
        cout << ansStr << endl;

    }

    // cout << checkakko(2) << endl;;
    return 0;
}