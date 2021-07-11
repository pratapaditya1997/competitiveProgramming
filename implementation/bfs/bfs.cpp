/* 
 * Author: aps
 * Time: 2019-10-20 23:19:32
**/
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = 1e18;
const ll mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}
inline ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0)
        x += mod;
    return x;
}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
inline ll power(ll a, ll b)
{
    ll x = 1;
    while (b)
    {
        if (b & 1)
            x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return power(a, mod - 2); }

const int N = 1e5 + 5;

int n, m;
vi g[N];
vector<bool> used;
vi d, p;

void bfs(int src) {
    queue<int> q;

    q.push(src);
    used[src] = true;
    p[src] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (used[u]) continue;
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    used.resize(n);
    d.resize(n);
    p.resize(n);
    bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "dist: " << d[i] << " par: " << p[i] << "\n";
    }

    return 0;
}
