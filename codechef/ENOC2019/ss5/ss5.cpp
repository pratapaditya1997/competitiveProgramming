/* 
 * Author: aps
 * Time: 2019-10-30 19:33:14
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

const int N = 5e4+4;

vi g[N];
vi cnt, grp, ans, vis;
int n;

void dfs(int v) {
    vis[v] = true;
    for(int u: g[v]) {
        if(!vis[u]) {
            dfs(u);
        }
    }
    cnt[grp[v]]++;
    int maxi = 0;
    for(int i=0; i<n; i++) maxi = max(maxi, cnt[i]);
    ans[v] = maxi;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    cnt.assign(n, 0);
    grp.assign(n, 0);
    ans.assign(n, 0);
    vis.assign(n, 0);

    for(int i=0; i<n; i++) {
        cin >> grp[i];
        grp[i]--;
    }

    for(int i=0; i<n-1; i++) {
        int v,u; cin >> v >> u;
        v--; u--;
        g[v].pb(u);
        g[u].pb(v);
    }

    dfs(0);
    for(int i=0; i<n; i++) cout << ans[i] << " ";

    return 0;
}
