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

int tenPerm(int n){
    int ans = 1;
    REP(i, n){
        ans *= 10;
    }
    return ans;
}

int main(){
    string S;
    cin >> S;

    if(S.size() == 1){
        if(S == "8"){
            out("Yes");
        }else{
            out("No");
        }
        return 0;
    }
    if(S.size() == 2){
        int num = stoi(S);
        if(num % 8 == 0){
            out("Yes");
            return 0;
        }

        swap(S[0], S[1]);
        num = stoi(S);
        if(num % 8 == 0){
            out("Yes");
            return 0;
        }

        out("No");
        return 0;
    }

    map<int, int> numCounts;
    REP(i, 10){
        numCounts[i] = 0;
    }
    REP(i, S.length()){
        int num = S[i] - '0';
        numCounts[num] += 1;
    }

    vector<string> eights;
    FOR(n, 100, 1000){
        if(n % 8 == 0){
            eights.push_back(to_string(n));
        }
    }

    for(auto num_s: eights){ 
        bool eightp = true;

        map<int, int> tmpnumCounts = numCounts;

        REP(i, num_s.length()){
            int num = num_s[i] - '0';
            if(tmpnumCounts[num] == 0){
                eightp = false;
                break;
            }else{
                tmpnumCounts[num] -= 1;
            }
        }

        if(eightp){
            out("Yes");
            return 0;
        }
    }

    out("No");

    return 0;
}