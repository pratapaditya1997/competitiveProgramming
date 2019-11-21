/* 
 * Author: aps
 * Time: 2019-11-20 18:12:31
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

template<class T>
vector<T> multiply(vector<T> a,vector<T> b) {
    int n = 1, sz1 = sz(a), sz2 = sz(b);
    while(n < sz(a) + sz(b)) n <<= 1;

    reverse(all(a));
    reverse(all(b));
    vector<T> result(n, 0);
    for(int i=0; i<sz1; i++) {
        for(int j=0; j<sz2; j++) {
            result[i+j] += a[i] * b[j]; 
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ++n;
        vi a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vi ans = multiply(a, b);
        
        n = 2 * n - 1;
        vi fin;
        for(int i=0; i<n; i++) fin.pb(ans[i]);
        reverse(all(fin));
        for(int i=0; i<n; i++) cout << fin[i] << " ";
        cout << "\n";
    }
    return 0;
}
