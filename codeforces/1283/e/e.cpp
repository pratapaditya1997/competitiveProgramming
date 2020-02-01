/* 
 * Author: aps
 * Time: 2019-12-28 23:21:37
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

const int N = 2e5+5;
int a[N], b[N], c[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;    
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[x] += 1; b[x] += 1; c[x] += 1;
    }

    // min
    for(int i=0; i<N-1; i++) {
        if(!b[i]) continue;
        if((i-1) >= 0 && b[i-1] > 0) {
            b[i-1] += b[i];
            b[i] = 0;
        }
        if(b[i+1]) {
            b[i+1] += b[i];
            b[i] = 0;
        }
    }

    // max
    for(int i=0; i<N-1; i++) {
        if(!c[i]) continue;
        if((i-1) >= 0 && c[i-1] == 0) {
            c[i-1] += 1;
            c[i] -= 1;
        }
        if(c[i+1] == 0 && c[i] > 1) {
            c[i+1] += 1;
            c[i] -= 1;
        }
    }

    int mini = 0, maxi = 0;
    for(int i=0; i<N-1; i++) {
        if(b[i] > 0) mini++;
        if(c[i] > 0) maxi++;
    }

    cout << mini << " " << maxi << endl;
    return 0;
}
