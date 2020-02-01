/* 
 * Author: aps
 * Time: 2019-11-30 20:35:42
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
    vi g[10004], sub, vals;
    int ans = 0;

    void dfs1(int v, int p) {
        //cout << v << endl;
        sub[v] = vals[v];
        for(int u: g[v]) {
            if(u != p) {
                dfs1(u, v);
                sub[v] += sub[u];
            }
        }
    }

    void dfs2(int v, int p) {
        if(sub[v] == 0) return;
        ans++;
        for(int u: g[v]) {
            if(u != p) dfs2(u, v);
        }
    }

    public:
    int deleteTreeNodes(int n, vi& par, vi& val) {
        sub.assign(n, 0);
        vals = val;

        for(int i=0; i<sz(par); i++) {
            if(par[i] == -1) continue;
            g[i].pb(par[i]);
            g[par[i]].pb(i);
        }

        dfs1(0, -1);
        
        ans = 0;
        dfs2(0, -1);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vi par = {-1,0,0,1,2,2,2};
    vi value = {1,-2,4,0,-2,-1,-1};
    cout << sol.deleteTreeNodes(7,par, value) << endl;
    return 0;
}
