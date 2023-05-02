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

int main(){
    string S;
    cin >> S;
    int A, B, C, D;
    A = S[0] - '0';
    B = S[1] - '0';
    C = S[2] - '0';
    D = S[3] - '0';
    vector<char> signs;
    signs.push_back('+');
    signs.push_back('-');

    for(char c1: signs){
        int val = A;
        int val2 = 0;
        if (c1 == '+'){
            val2 = val + B;
        }else{
            val2 = val - B;
        }

        for(char c2: signs){
            int val3 = 0;
            if (c2 == '+'){
                val3 = val2 + C;
            }else{
                val3 = val2 - C;
            }
            for(char c3: signs){
                int val4 = 0;
                if (c3 == '+'){
                    val4 = val3 + D;
                }else{
                    val4 = val3 - D;
                }

                if(val4 == 7){
                    cout << A << c1 << B << c2 << C << c3 << D << "=7" << endl;
                    return 0;
                }
            }
            
        }

    }
    return 0;
}