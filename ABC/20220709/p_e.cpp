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

int main(){
    int N;
    cin >> N;
    vector<int> mi(N);
    vector<vector<LL>> pi(N);
    vector<vector<LL>> ei(N);
    set<LL> p_all;
    map<LL, pair<LL, LL>> counter;
    REP(i, N){
        cin >> mi[i];
        REP(j, mi[i]){
            LL p, e;
            cin >> p >> e;
            p_all.insert(p);
            pi[i].push_back(p);
            ei[i].push_back(e);
            if(counter.find(p) == counter.end()){
                counter[p] = {e, 0};
            }else{
                if(counter[p].first <= e){
                    counter[p].second = counter[p].first;
                    counter[p].first = e;
                    continue;
                }
                if(counter[p].second <= e){
                    counter[p].second = e;
                }
            }
        }
    }

    set<set<pair<LL, LL>>> gcds;
    REP(i, N){
        vector<LL> ps = pi[i];
        vector<LL> es = ei[i];

        set<pair<LL, LL>> tmp_gcds;
        tmp_gcds.insert({1, 1});
        REP(j, ps.size()){
            LL p = ps[j];
            LL e = es[j];
            // 削除されることで変化するか
            if(counter[p].first == e){
                if(counter[p].second != counter[p].first){
                    tmp_gcds.insert({p, counter[p].second});
                    // cout << p << ", " << counter[p].second << endl;
                }
            }
        }
        if(tmp_gcds.size() == 0){
            tmp_gcds.insert({1, 1});
        }
        gcds.insert(tmp_gcds);
        // for(auto gcd: tmp_gcds){
        //     cout << gcd.first << ", " << gcd.second << endl;
        // }
    }

    out(gcds.size());

    return 0;
}
