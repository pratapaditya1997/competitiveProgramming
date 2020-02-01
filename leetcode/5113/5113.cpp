/* 
 * Author: aps
 * Time: 2019-11-30 20:13:46
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
 
const ll inf = 1e18;
const ll mod = 1e9+7;
 
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
inline ll power(ll a, ll b) {
    ll x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return power(a, mod - 2);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
    public:
    vvi removeInterval(vvi& intervals, vi& rem) {
        vvi ret;
        for(vi v: intervals) {
            vi toInsert;
            if(rem[0] > v[1] || rem[1] < v[0]) ret.pb(v);
            else {
                if(v[0] > rem[0] && v[1] < rem[1]) {
                    // over
                    continue;
                }
                if(v[0] < rem[0] && v[1] > rem[1]) {
                    // full inside
                    toInsert = {v[0],rem[0]};
                    ret.pb(toInsert);
                    toInsert = {rem[1], v[1]};
                    ret.pb(toInsert);
                    continue;
                }
                if(v[0] < rem[1] && v[1] > rem[1]) {
                    //l to r
                    toInsert = {rem[1], v[1]};
                    ret.pb(toInsert);
                    continue;
                }
                toInsert = {v[0], rem[0]};
                ret.pb(toInsert);
            }
        }

        sort(all(ret));
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vvi v = {{0,2},{3,4},{5,7}};
    vi vv = {1,6};
    vvi res = sol.removeInterval(v,vv);

    for(vi resV: res) {
        for(int val: resV) cout << val << " ";
        cout << endl;
    }
    return 0;
}
