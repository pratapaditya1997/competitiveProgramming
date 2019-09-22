/* 
 * Author: aps
 * Time: 2019-08-01 18:15:37
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
ll cnt[N], ans[N], answer=1L;

ll n,k;

void dfs(int u, int par){
    ll val = 1LL;
    if(u == 1) val = 0LL;

    ans[u] = max(0LL,k - val - cnt[par]);

    cnt[u] = 1LL;
    if(u == 1) cnt[u] = 0LL;

    for(int v: g[u]){
        if(v != par){
            dfs(v,u);
            cnt[u] += 1LL;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    cnt[0] = 0;
    dfs(1,0);

    answer = 1LL;

    for(int i=1;i<=n;i++) {
        answer = mul(answer,ans[i]);
    }

    cout << answer << endl;

    return 0;
}
