/* 
 * Author: aps
 * Time: 2019-10-29 20:39:59
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

const int N = 1e5+5;

vector<pii> g[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        if(u == v) continue;
        g[u].pb({v,0});
        g[v].pb({u,1});
    }

    vi d(n+1, mod);
    d[1] = 0;

    deque<int> q;
    q.push_front(1);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(pii edge: g[v]) {
            int u = edge.fi;
            int w = edge.se;
            if(d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if(w == 1) q.push_back(u);
                else q.push_front(u);
            }
        }
    }

    if(d[n] == mod) d[n] = -1;
    cout << d[n] << "\n";

    return 0;
}
