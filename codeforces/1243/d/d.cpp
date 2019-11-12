/* 
 * Author: aps
 * Time: 2019-11-11 18:50:56
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

const int N = 1e5+5;

set<int> g[N];
set<int> unused;

int cc = 0;

void dfs(int v) {
    unused.erase(v);
    int cur = -1;
    while(1) {
        auto it = unused.upper_bound(cur);
        if(it == unused.end()) break;
        cur = *it;
        if(!g[v].count(cur)) dfs(cur);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        --u; --v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for(int i=0; i<n; i++) unused.insert(i);
    for(int i=0; i<n; i++) {
        if(unused.count(i)) {
            cc++;
            dfs(i);
        }
    }

    cout << cc-1 << "\n";
    return 0;
}
