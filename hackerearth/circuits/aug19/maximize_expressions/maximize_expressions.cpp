/* 
 * Author: aps
 * Time: 2019-08-29 12:40:52
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
    
    ll n, ans = 0; cin >> n;
    vl a(n),b(n),c(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    for(int i=0;i<n;i++){
        ll x = (a[i] ^ b[i]);
        ll d = c[i], lastSet;
        for(int j=32;j>=0;j--){
            if((c[i] & (1L<<j)) == 0) continue;
            //cout << "c[i]: " << c[i] << " set on: " << j << "\n";
            if((x & (1L<<j))){
                lastSet = j;
                d = (d ^ (1LL<<j));
            }
        }
        if(d == 0) {
            d = (1L<<lastSet);
        }
        ans += (x ^ d);
        //cout << "x: " << x << " d: " << d << "\n";
    }

    cout << ans << "\n";
    return 0;
}
