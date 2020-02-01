/* 
 * Author: aps
 * Time: 2019-11-29 20:21:08
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

class dsu {
    public:
    vector<int> p;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dsu d(n);
    vl v;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        ll bit = 0;
        for(char ch: s) {
            bit |= (1LL<<(ch-'a'));
        }
        v.pb(bit);
    }

    for(int j=27; j>=0; j--) {
        vi same;
        for(int i=0; i<n; i++) {
            if(v[i] & (1LL<<j)) same.pb(i);
        }
        for(int i=0; i+1<sz(same); i++) {
            d.unite(same[i], same[i+1]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(d.get(i) == i) ans++;
    }
    cout << ans << "\n";
    return 0;
}
