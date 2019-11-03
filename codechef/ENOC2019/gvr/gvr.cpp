/* 
 * Author: aps
 * Time: 2019-10-31 10:56:07
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

const int iters = 50;

ll powerMod(ll a, ll b, ll MOD) {
    ll x = 1LL;
    while(b) {
        if(b&1) x = ((x%MOD) * (a*MOD))%MOD;
        a = ((a%MOD) * (a%MOD))%MOD;
        b >>= 1;
    }
    return x % MOD;
}

bool isPrime(ll n) {
    if(n == 1 || n == 4) return false;
    if(n <= 3) return true;
    for(int i=0; i<iters; i++) {
        ll x = 2 + rand()%(n-4);
        if(gcd(n,x) != -1) return false;
        if(powerMod(x,n-1,n) != 1) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    
    ll x, flag = 0, val1 = 0, cnt1 = 0, cnt2 = 0, val2 = 0;
    for(int i=0; i<n/2; i++) {
        cin >> x;
        if(isPrime(x)) {
            ++cnt1;
            if(!flag) {
                flag = 1;
                val1 = x;
            }
        }
    }

    for(int i=0; i<n/2; i++) {
        cin >> x;
        if(isPrime(x)) {
            ++cnt2;
            val2 = x;
        }
    }

    if(cnt1 == cnt2 && val1 > val2) {
        cout << "PERFECT";
    } else {
        cout << "IMPERFECT";
    }

    return 0;
}
