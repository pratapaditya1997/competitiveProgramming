/* 
 * Author: aps
 * Time: 2019-09-22 22:13:56
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

const int N = 2002;

ll mat[N][N], cmat[N][N], f[N];

void pre() {
    for(int i=1;i<N;i++) mat[i][1] = 1;
    cmat[1][1] = 1; cmat[2][1] = 2;

    for(int i=3;i<N;i++) {
        int idx = i-2;
        for(int j = 1; j <= idx; j++) {
            mat[i][j+1] = mul(cmat[idx][j],j+1);
        }
        for(int j = 1;j <= i; j++) {
            cmat[i][j] = add(mat[i][j],cmat[i-1][j]);
        }
    }

    for(int i=1;i<N;i++){
        ll ans = 0;
        for(int j=1;j<=i;j++) {
            ans = add(ans,mat[i][j]);
        }
        f[i] = ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    pre();
    ll n; cin >> n;
    
    ll ans = 0LL;
    for(int i=1;i<=n;i++) {
        ans = add(ans,f[i]);
    }
    cout << ans << "\n";

    return 0;
}
