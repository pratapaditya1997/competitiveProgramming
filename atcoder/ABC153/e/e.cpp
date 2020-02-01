/* 
 * Author: aps
 * Time: 2020-01-26 22:48:51
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

const int MX = 2e4+4;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h,n; cin >> h >> n;
    vi a(n+1,0), b(n+1,0);

    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }

    vvi dp(n+1, vi (h+1, 1e8));
    dp[0][0] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=h; j++) {
            int val = dp[i][j];
            int prev = max(0, j-a[i]);
            val = min(val, dp[i][prev] + b[i]);
            val = min(val, dp[i-1][j]);
            dp[i][j] = val;
        }
    }

    cout << dp[n][h] << "\n";
    return 0;
}


















