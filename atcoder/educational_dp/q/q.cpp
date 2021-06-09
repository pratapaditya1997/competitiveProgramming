/* 
 * Author: aps
 * Time: 2021-06-08 21:08:31
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

vector<int> st;

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return -1e5;
    if (l == tl && r == tr) return st[v];

    int tm = (tl + tr)/2;
    return max(query(v*2, tl, tm, l, min(r, tm)),
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        st[v] = val;
        return;
    }

    int tm = (tl + tr)/2;
    if (pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2+1, tm+1, tr, pos, val);

    st[v] = max(st[v*2], st[v*2+1]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vector<int> h(n), a(n), dp(n, 0);
    st = vector<int>(4*n, 0);

    for (int i=0; i<n; ++i) {
        cin >> h[i];
        --h[i];
    }
    for (int i=0; i<n; ++i) cin >> a[i];

    int ans = 0;
    for (int i=0; i<n; ++i) {
        int val = query(1, 0, n-1, 0, h[i]);
        dp[h[i]] = val + a[i];
        ans = max(ans, dp[h[i]]);
        update(1, 0, n-1, h[i], dp[h[i]]);
    }

    cout << ans << '\n';
    return 0;
}
