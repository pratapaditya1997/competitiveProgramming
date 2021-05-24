/* 
 * Author: aps
 * Time: 2019-11-11 18:16:58
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

set<int> g[N];
set<int> unvis;

int cc = 0;
vi comps;

void dfs(int v) {
    unvis.erase(v);
    comps[cc]++;
    int cur = -1;
    while(1) {
        auto it = unvis.upper_bound(cur);
        if(it == unvis.end()) break;
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

    for(int i=0; i<n; i++) unvis.insert(i);
    for(int i=0; i<n; i++) {
        if(unvis.count(i)) {
            comps.pb(0);
            dfs(i);
            ++cc;
        }
    }

    sort(all(comps));
    cout << cc << "\n";
    for(int v: comps) cout << v << " ";
    cout << "\n";
    
    return 0;
}
