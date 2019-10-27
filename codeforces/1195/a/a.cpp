/* 
 * Author: aps
 * Time: 2019-07-20 19:03:32
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

const int N = 1005;

int cnt[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        x--;
        cnt[x]++;
    }

    int ans = 0, left = 0;
    for(int i=0;i<k;i++){
        ans += cnt[i]/2;
        if(cnt[i] & 1) left++;
    }
    ans *= 2;
    ans += left/2;
    if(left & 1) ans++;
    cout << ans << endl;
    return 0;
}
