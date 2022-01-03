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

LL gcd(LL vala, LL valb){
    if(vala == 0){
        return valb;
    }
    LL val_new = valb % vala;
    return gcd(val_new, vala);
}

int get_digits(LL val){
    string val_str = to_string(val);
    return (int)val_str.size() - 1;
}

int mul_top_nums(vector<LL> vals){
    int ans = 1;
    for(auto v : vals){
        string v_str = to_string(v);
        int v_top = v_str[0] - '0';
        ans *= v_top;
    }
    return ans;
}

int main(){
    LL A, B;
    cin >> A >> B;

    LL large = (A > B)? A : B;
    LL small = (A > B)? B : A;

    LL val = gcd(small, large);

    LL val1 = A / val;
    LL val2 = B / val;


    int mul_top = mul_top_nums(vector<LL>{val, val1, val2});
    int total_digit = get_digits(val) + get_digits(val1) + get_digits(val2) + get_digits(mul_top);

    if(total_digit > 18){
        cout << "Large" << endl;
        return 0;
    }else if(total_digit == 18){
        int top = mul_top_nums(vector<LL>{mul_top});
        if(top > 1){
            cout << "Large" << endl;
            return 0;
        }
    }

    LL ans = val * val1 * val2;
    if( ans > 1E18L){
        cout << "Large" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}