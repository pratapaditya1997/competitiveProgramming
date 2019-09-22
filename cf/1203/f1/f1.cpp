/* 
 * Author: aps
 * Time: 2019-08-18 21:23:23
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

bool cmp1(pii a, pii b){
    return a.fi < b.fi;
}

bool cmp2(pii a,pii b) {
    return (a.fi + a.se > b.fi + b.se);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    ll rating; cin >> n >> rating;

    vector<pii> pos,neg;
    for(int i=0;i<n;i++){
        int r,g; cin >> r >> g;
        if(g >= 0) pos.pb({r,g});
        else neg.pb({r,g});
    }

    sort(all(pos),cmp1);
    sort(all(neg),cmp2);

    bool ok = true;
    for(pii p: pos){
        if(rating < p.fi){
            ok = false;
            break;
        } 
        rating += p.se;
        if(rating < 0){
            ok = false;
            break;
        }
    }

    if(ok){
        for(pii p: neg){
            if(rating < p.fi){
                ok = false;
                break;
            }
            rating += p.se;
            if(rating < 0) {
                ok = false;
                break;
            }
        }
    }
    
    string ans = (ok) ? "YES\n" : "NO\n";
    cout << ans;

    return 0;
}
