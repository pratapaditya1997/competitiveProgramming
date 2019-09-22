/* 
 * Author: aps
 * Time: 2019-07-20 20:32:18
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
    ll n,k; cin >> n >> k;
    ll x = 0, lo = 0, hi = 1e6, tar = 2*(n+k);
    while(lo <= hi){
        ll m = (lo + hi)/2;
        ll val = m*m + 3*m;
        if(val == tar) {
            x = m;
            break;
        } else if(val < tar) lo = m+1;
        else hi = m-1;
    }
    cout << n-x << endl;
    return 0;
}
