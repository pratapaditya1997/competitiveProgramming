/* 
 * Author: aps
 * Time: 2019-11-20 17:43:26
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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = sz(a);
    
    for(int i=1,j=0; i<n; i++) {
        int bit = n >> 1;
        for(; j&bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }

    for(int len=2; len<=n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i=0; i<n; i+=len) {
            cd w(1);
            for(int j=0; j<len/2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }

    if(invert) {
        for(cd& x: a) x /= n;
    }
}

template<class T>
vector<T> multiply(vector<T> const& a,vector<T> const& b) {
    vector<cd> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < sz(a) + sz(b)) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for(int i=0; i<n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<T> result(n);
    for(int i=0; i<n; i++) result[i] = round(fa[i].real());
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    vl a = {1,2,3};
    vl b = {3,2,1};
    vl res = multiply(a, b);
    
    int n = sz(a) + sz(b) - 1;
    for(int i=0; i<n; i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}
