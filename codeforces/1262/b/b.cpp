/* 
 * Author: aps
 * Time: 2019-11-24 13:55:31
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi firstSeen(n+1, -1);
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if(firstSeen[x] == -1) firstSeen[x] = i;
        }

        set<int> left;
        for(int i=1; i<=n; i++) left.insert(i);

        vi ans(n, 0);
        for(int i=1; i<=n; i++) {
            if(firstSeen[i] != -1) {
                ans[firstSeen[i]] = i;
                left.erase(i);
            }
        }

        int notPossible = 0;
        for(int i=0; i<n; i++) {
            if(ans[i] == 0) {
                int prev = ans[i-1];
                auto it = left.lower_bound(prev);
                if(it == left.begin()) {
                    notPossible = 1;
                    break;
                }
                it--;
                ans[i] = *it;
                left.erase(*it);
            }
        }

        if(notPossible) cout << -1 << endl;
        else {
            for(int v: ans) cout << v << " ";
            cout << endl;
        }
    }
    return 0;
}
