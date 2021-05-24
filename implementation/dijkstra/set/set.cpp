/* 
 * Author: aps
 * Time: 2021-02-19 17:13:27
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

const int N = 1e4+4;

vector<pii> g[N];
vi d;

void dijk(int s) {
    d[s] = 0;
    set<pii> q;
    q.insert({0,s});
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for(auto edge: g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v,w; cin >> u >> v >> w;
        g[u].pb({v,w});
    }

    d.assign(n,mod);
    dijk(0);

    for(int i=0; i<n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
