/* 
 * Author: aps
 * Time: 2019-08-18 00:48:58
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

const int N = 2e5+5;
int l[N], r[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t; cin >> s >> t;
    int n = s.length(), m = t.length();

    l[0] = r[0] = -1;
    l[m+1] = r[m+1] = n;

    int j = 0;
    for(int i=0;i<n;i++){
        if(s[i] == t[j]){
            l[j+1] = i;
            ++j;
        }
    }

    j = m-1;
    for(int i=n-1;i>=0;i--){
        if(s[i] == t[j]){
            r[j+1] = i;
            --j;
        }
    }

    int ans = 0;
    for(int i=0;i<=m;i++) {
        int L = l[i], R = r[i+1];
        ans = max(ans,R-L-1);
    }

    cout << ans << endl;
    return 0;
}
