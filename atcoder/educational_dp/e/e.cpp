/* 
 * Author: aps
 * Time: 2021-05-24 21:23:47
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

const int V = 1e5 + 5;  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, W; cin >> n >> W;
    vector<ll> w(n + 1), v(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(V + 1, inf));

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; ++j) {
            ll ret = dp[i - 1][j];
            if (j - v[i] >= 0) ret = min(ret, w[i] + dp[i - 1][j - v[i]]);
            dp[i][j] = ret;
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= 20; ++j) {
    //         cout << "i: " << i << " j: " << j << " val: " << dp[i][j] << '\n';
    //     }
    // }

    int ans = 0;
    for (int j = 1; j <= V; ++j) {
        if (dp[n][j] <= W) ans = j;
    }

    cout << ans << '\n';
    return 0;
}
