/* 
 * Author: aps
 * Time: 2019-09-28 14:05:52
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

const int N = 1e6+6;
vi g[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll n,m,k; cin >> n >> m >> k;
    vl cur(n+1,0LL);
    vl ans(n+1,-1);

    for(int i=0;i<m;i++){
        ll u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int q; cin >> q;
    for(int i=0;i<q;i++) {
        ll u,x; cin >> u >> x;
        for(int v: g[u]){
            cur[v] += x;
            if(cur[v] >= k && ans[v] == -1) {
                ans[v] = i+1;
            }
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
