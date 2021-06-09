/* 
 * Author: aps
 * Time: 2021-05-24 22:42:55
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

vector<vector<int>> g;
vector<int> dp;

int ans = 0;

void Dfs(int v) {
    int ret = -1;
    for (int to: g[v]) {
        if (dp[to] == -1) {
            Dfs(to);
        }
        ret = max(ret, dp[to]);
    }
    dp[v] = ret + 1;
    ans = max(ans, dp[v]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;

    g = vector<vector<int>> (n + 1, vector<int>());
    dp = vector<int>(n + 1, -1);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) {
            Dfs(i);
        }
    }

    cout << ans << '\n';
    return 0;
}
