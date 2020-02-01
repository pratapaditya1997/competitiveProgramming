/* 
 * Author: aps
 * Time: 2019-11-29 13:58:20
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
        int n,k; cin >> n >> k;
        string s,t = ""; cin >> s;
        
        for(int i=0; i<k-1; i++) t += "()";
        for(int i=0; i<n/2+1-k; i++) t += "(";
        for(int i=0; i<n/2+1-k; i++) t += ")";

        vector<pii> moves;
        for(int i=0; i<n; i++) {
            if(s[i] != t[i]) {
                for(int j = i+1; j<n; j++) {
                    if(s[j] == t[i]) {
                        moves.pb({i+1 ,j+1});
                        reverse(s.begin()+i, s.begin() + j + 1);
                        break;
                    }
                }
            }
        }

        cout << sz(moves) << "\n";
        for(auto x: moves) cout << x.fi << " " << x.se << "\n";
    }
    return 0;
}
