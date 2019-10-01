/* 
 * Author: aps
 * Time: 2019-09-21 21:38:46
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

const ll N = 1e6+6;
ll fact[N];

void pre() {
    fact[1]=1LL;
    for(ll i=2;i<N;i++) {
        fact[i] = mul(fact[i-1],i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    pre();
    ll m,n; cin >> n >> m;
    cout << fact[m] << "\n";
    return 0;
}
