/* 
 * Author: aps
 * Time: 2021-06-08 20:37:34
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
vector<ll> white_dp, black_dp;

void Dfs(int v, int p) {
    white_dp[v] = black_dp[v] = 1;
    for (int to: g[v]) {
        if (to == p) continue;
        Dfs(to, v);
        white_dp[v] = mul(white_dp[v], add(white_dp[to], black_dp[to]));
        black_dp[v] = mul(black_dp[v], white_dp[to]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    g = vector<vector<int>> (n+1, vector<int>());
    white_dp = vector<ll> (n+1, 0);
    black_dp = vector<ll> (n+1, 0);

    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    Dfs(1, 0);
    cout << add(white_dp[1], black_dp[1]) << '\n';
    return 0;
}