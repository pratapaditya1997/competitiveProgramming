/* 
 * Author: aps
 * Time: 2021-05-24 20:29:27
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vector<ll> h(n);
    vector<ll> dp(n, inf);

    for (int i=0; i<n; ++i) cin >> h[i];
    
    dp[0] = 0;
    for (int i=1; i<n; i++) {
        ll val1 = inf, val2 = inf;
        if (i - 1 >= 0) val1 = min(val1, dp[i - 1] + abs(h[i] - h[i-1]));
        if (i - 2 >= 0) val2 = min(val2, dp[i - 2] + abs(h[i] - h[i-2])); 
        dp[i] = min(val1, val2);
    }

    cout << dp[n-1] << '\n';
    return 0;
}
