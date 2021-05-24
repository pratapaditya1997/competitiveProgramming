/* 
 * Author: aps
 * Time: 2019-10-27 22:49:19
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
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
vi d,p;

void dijk(int s) {
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, s});
    while(!pq.empty()) {
        int v = pq.top().se;
        int dv = pq.top().fi; pq.pop();
        
        // removing older pairs of node v
        if(dv != d[v]) continue;
        // relaxing edges
        for(pii edge: g[v]) {
            int to = edge.fi;
            int len = edge.se;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({d[to], to});
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

    d.assign(n, mod);
    p.assign(n, -1);
    dijk(0);

    for(int i=0; i<n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
