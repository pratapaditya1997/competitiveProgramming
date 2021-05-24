/* 
 * Author: aps
 * Time: 2019-11-29 17:36:36
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

/*
* 0-based implementation
*/
template <typename T>
class fenwick {
public:
    vector<T> bit;
    int n;
 
    fenwick(int _n): n(_n) {
        bit.resize(n);
    }

    fenwick(const vector<T>& a): fenwick(size(a)) {
        for(size_t i=0; i<size(a); i++) {
            modify(i, a[i]);
        }
    }
 
    void modify(int x, T v) {
        while(x < n) {
            bit[x] += v;
            x |= (x+1);
        }
    }

    void modify_range(int l, int r, T v) {
        modify(l, v);
        modify(r + 1, -v);
    }
 
    T get(int x) {
        T ret{};
        while(x >= 0) {
            ret += bit[x];
            x = (x & (x+1)) - 1;
        }
        return ret;
    }

    T getRange(int l, int r) {
        return get(r) - get(l-1);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    return 0;
}
