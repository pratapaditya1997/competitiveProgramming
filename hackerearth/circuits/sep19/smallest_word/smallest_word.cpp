/* 
 * Author: aps
 * Time: 2019-09-22 21:17:48
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int a,b,c; cin >> a >> b >> c;
    string p,q,r,ans=""; cin >> p >> q >> r;
    
    ans = p;
    
    vi pos[26];
    for(int i=0;i<b;i++){
        int idx = q[i]-'a';
        pos[idx].pb(i);
    }

    for(int i=0;i<26;i++){
        sort(all(pos[i]));
    }

    int lastIdx = -1;
    if(c != 0) {
        int lim = r[0]-'a';
        for(int i=0;i<lim;i++) {
            for(int j: pos[i]) {
                if(j >= lastIdx) {
                    ans += char(i+'a');
                    lastIdx = j;
                }
            }
        }
        int k = 0;
        for(; k < c && r[k]==r[0]; k++);

        if(r[k] > r[0]) {
            for(int j: pos[lim]) {
                if(j >= lastIdx) {
                    ans += char(lim+'a');
                    lastIdx = j;
                }
            }
        }        
    }
    
    ans += r;

    cout << ans << "\n";
  
    return 0;
}
