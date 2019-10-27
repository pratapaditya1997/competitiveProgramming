/* 
 * Author: aps
 * Time: 2019-08-17 22:26:27
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

ll divs(ll n){
    ll ret = 0;
    for(ll i=1;i<=sqrt(n);i++){
        if(n % i == 0L){
            ret += 2L;
            if(i * i == n) ret--;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;

    ll x,g; cin >> x;
    g = x;
    for(int i=0;i<n-1;i++) {
        cin >> x;
        if(x < g) swap(g,x);
        g = gcd(g,x);
    }

    cout << divs(g) << endl;
    return 0;
}
