/* 
 * Author: aps
 * Time: 2019-11-02 20:40:32
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

bool query(ll l, ll r) {
    cout << l << " " << r << endl;
    string ans; cin >> ans;
    if(ans == "Bad") exit(0);
    if(l == r && ans == "Yes") exit(0);
    return ans == "Yes";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll n,k; cin >> n >> k;
    ll lo = 1, hi = n;

    while(true) {
        bool ok = (hi - lo) <= 5*k + 1;
        if(ok) {
            ll loc = uniform_int_distribution<ll>(lo, hi)(rng);
            query(loc,loc);
        } else {
            ll mid = (lo + hi) / 2;
            if(query(lo,mid)) {
                hi = mid;
            } else lo = mid+1;
        }
        lo = max(lo - k, 1LL);
        hi = min(hi + k, n);
    }

    return 0;
}
