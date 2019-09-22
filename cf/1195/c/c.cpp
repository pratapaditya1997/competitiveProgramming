/* 
 * Author: aps
 * Time: 2019-07-20 20:56:46
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
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    
    vl a(n),b(n);
    vector<vl> dp(n,vl (2));

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    dp[0][0] = a[0];
    dp[0][1] = b[0];

    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+a[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+b[i]);
    }

    cout << max(dp[n-1][0],dp[n-1][1]) <<endl;
    
    return 0;
}
