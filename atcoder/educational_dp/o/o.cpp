/* 
 * Author: aps
 * Time: 2021-06-08 19:58:56
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

const int N = 22;
int n;
ll dp[N][(1<<N)], can[N][N];

ll f(int pos, int mask) {
    if (pos == n) return 1;
    if (dp[pos][mask] != -1) return dp[pos][mask];

    ll ret = 0;
    for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
            continue;
        } else {
            // can use ith woman
            ret = add(ret, f(pos+1, mask|(1<<i)) * can[pos][i]);
        }
    }
    return (dp[pos][mask] = ret);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) cin >> can[i][j];
    }

    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << '\n';
    return 0;
}
