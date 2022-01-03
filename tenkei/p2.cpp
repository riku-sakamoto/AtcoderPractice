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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


// カッコの判定
bool hantei(string kakkos){
    int dep = 0;
    REP(i, kakkos.size()){
        char kakko = kakkos[i];
        if(kakko == '(') dep+=1;
        if(kakko == ')') dep-=1;
        if(dep < 0) return false;
    }
    if(dep == 0) return true;

    return false;

}

int main(){
    int N;
    cin >> N;
    
    for(int i=0; i < (1<<N); i++){
        string Candidate = "";

        for(int j=N-1; j>=0; j--){
            // iのjビット目が0であるか
            if( (i & (1 << j)) == 0){
                Candidate += "(";
            }else{
                Candidate += ")";
            }
        }

        bool isOK = hantei(Candidate);
        if(isOK){
            cout << Candidate << endl;
        }
    }

    return 0;
}