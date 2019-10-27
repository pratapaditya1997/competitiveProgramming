/* 
 * Author: aps
 * Time: 2019-08-25 17:27:59
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

const int N = 105, R = 1e5+5;

bool comp(pii a, pii b){
    if(a.se >=0 && b.se >= 0){
        return a.fi < b.fi;
    } else if (a.se < 0 && b.se < 0) {
        return a.fi + a.se > b.fi + b.se;
    } else return a.se >= 0;
}

int dp[N][R];
pii p[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,r,ans = 0; cin >> n >> r;
    for(int i=1;i<=n;i++) cin >> p[i].fi >> p[i].se;

    sort(p+1,p+n+1,comp);

    for(int j=0;j<R;j++) dp[0][j] = -1000;
    dp[0][r] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<R;j++){
            dp[i][j] = dp[i-1][j]; // not taking ith task
            if(j-p[i].se >= p[i].fi && j-p[i].se < R) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-p[i].se]+1);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
        
    return 0;
}
