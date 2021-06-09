/* 
 * Author: aps
 * Time: 2021-06-08 19:08:46
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
    
    int n, K; cin >> n >> K;

    vector<ll> a(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(K+1)),
                       pre(n+1, vector<ll>(K+1));
    
    for (int i=1; i<=n; ++i) cin >> a[i];

    for (int i=0; i<=n; ++i) dp[i][0] = pre[i][0] = 1;
    for (int j=0; j<=K; ++j) pre[0][j] = 1;

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=K; ++j) {
            ll first = (j-a[i]-1 >= 0) ? pre[i-1][j-a[i]-1] : 0;
            ll last = pre[i-1][j];
            dp[i][j] = add(dp[i][j], sub(last, first));
            pre[i][j] = add(pre[i][j-1], dp[i][j]);
        }
    }

    cout << dp[n][K] << '\n';
    return 0;
}
