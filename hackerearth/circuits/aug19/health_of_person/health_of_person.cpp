/* 
 * Author: aps
 * Time: 2019-08-24 21:37:47
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

const int N = 1e6+6;

int ans[N], a[N], b[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    clock_t start = clock();
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            ans[i] = -1;
        }
        for(int i=1;i<=m;i++) cin >> b[i];

        for(int i=1;i<=m;i++){
            for(int j=i;j<=n;j+=i){
                if(ans[j] == -1 && a[j] <= b[i]) ans[j] = i;
            }
        }

        for(int i=1;i<=n;i++) cout << ans[i] << endl;
    }
    clock_t end = clock();
    cerr << "Time: " << (double)(end-start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
