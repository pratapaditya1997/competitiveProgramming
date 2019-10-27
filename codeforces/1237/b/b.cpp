/* 
 * Author: aps
 * Time: 2019-10-20 17:39:29
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vi a(n), b(n), mp(n+1);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
        b[i] = mp[b[i]];
    }

    int ans = 0, rmin = INT_MAX;
    for(int i=n-1; i>=0 ;i--) {
        if(b[i] > rmin) ans++;
        rmin = min(rmin, b[i]);
    }

    cout << ans << "\n";

    return 0;
}
