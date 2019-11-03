/* 
 * Author: aps
 * Time: 2019-10-30 19:07:13
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

const int N = 1e5+5;

vi g[N];
vi lev, vis;
int n;

void dfs(int v, int depth) {
    lev[depth] += 1;
    vis[v] = true;

    for(int u: g[v]) {
        if(!vis[u]) dfs(u, depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int from,to; cin >> from >> to;
        g[from].pb(to);
        g[to].pb(from);
    }

    lev.assign(n+1, 0);
    vis.assign(n+1, 0);
    dfs(1,1);

    int best=0, ans=1;
    for(int i=1; i<=n; i++) {
        if(lev[i] > best) {
            best = lev[i];
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
