/* 
 * Author: aps
 * Time: 2019-11-03 17:16:36
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int a,b; cin >> a >> b;
    
    vvl dp(a+1, vl(b+1, mod));
    for(int i=0; i <= min(a,b); i++) dp[i][i] = 0;

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int r=1; r<i; r++) {
                dp[i][j] = min(dp[i][j], dp[r][j] + dp[i-r][j] + 1);
            }
            for(int c=1; c<j; c++) {
                dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j-c] + 1);
            }
        }
    }

    cout << dp[a][b] << "\n";

    return 0;
}
