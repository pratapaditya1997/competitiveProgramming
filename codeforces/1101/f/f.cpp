/* 
 * Author: aps
 * Time: 2019-11-09 19:27:08
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

const int N = 3e5+5;
const int M = 500;

int n, m, a[M], s[N], f[N], c[N], r[N], perm[N];

bool check(ll gas, int id) {
    ll tot = 0, cnt = r[id];
    for(int i=s[id]+1; i<=f[id]; i++) {
        ll reqd = 1LL * c[id] * (a[i] - a[i-1]);
        tot += reqd;
        if(tot > gas) {
            if(cnt == 0) return false;
            --cnt;
            tot = reqd;
            if(tot > gas) return false;
        }
    }
    return true;
}

ll getAns(int id) {
    ll l=1, r = 1e18, ans=0;
    while(l <= r) {
        ll m = (l+r)/2;
        if(check(m, id)) {
            ans = m;
            r = m-1;
        } else l = m+1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) {
        cin >> s[i] >> f[i] >> c[i] >> r[i];
        --s[i]; --f[i];
        perm[i] = i;
    }
    shuffle(perm, perm + m, rng);
    
    ll ans = 0;
    for(int i=0; i<m; i++) {
        if(!check(ans, perm[i])) {
            ans = getAns(perm[i]);
        }
    }
    cout << ans << "\n";

    return 0;
}
