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

int main(){
    int N, M;
    cin >> N >> M;
    vector<LL> w(N, 0);
    REP(i, N){cin >> w[i];}
    vector<LL> l(M, 0);
    vector<LL> v(M, 0);
    REP(i, M){cin >> l[i] >> v[i];}
    
    LL w_max = *max_element(w.begin(), w.end());
    LL v_min = *min_element(v.begin(), v.end());

    if(w_max > v_min){
        cout << -1 << endl;
        return 0;
    }

    LL l_max = *max_element(l.begin(), l.end());

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            
        }        
    }


}