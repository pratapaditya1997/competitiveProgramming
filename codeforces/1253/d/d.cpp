/* 
 * Author: aps
 * Time: 2019-11-17 21:27:57
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

const int N = 2e5+5;

vi g[N], vis;
vector<pii> evs;

void dfs(int v,int& l, int& r) {
    vis[v] = 1;
    l = min(l,v);
    r = max(r,v);

    for(int u: g[v]) {
        if(!vis[u]) {
            dfs(u,l,r);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;

    vis.assign(n+1, 0);
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            int l=i, r=i;
            dfs(i,l,r);
            evs.pb({l,r});
        }
    }

    int ans=0, r=-1;
    for(pii p: evs) {
        if(p.fi < r) ++ans;
        r = max(r, p.se);
    }

    cout << ans << "\n";
    return 0;
}
