/* 
 * Author: aps
 * Time: 2019-10-27 14:03:14
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
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vi d(10005,-1);
        d[n] = 0;

        queue<int> q;
        q.push(n);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(cur == m) break;
            if(2*cur < 10005 && d[2*cur] == -1) {
                d[2*cur] = d[cur] + 1;
                q.push(2*cur);
            }
            if(cur-1 >= 0 && d[cur-1] == -1) {
                d[cur-1] = d[cur] + 1;
                q.push(cur-1);
            }
        }

        cout << d[m] << "\n";
    }
    return 0;
}
