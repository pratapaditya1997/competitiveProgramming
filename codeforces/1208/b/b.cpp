/* 
 * Author: aps
 * Time: 2019-08-25 20:14:48
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

const int N = 2005;

ll a[N],n;

map<ll,ll> cnt;

bool fine(){
    for(pii p: cnt){
        if(p.se > 1) return false;
    }
    return true;
}

bool check(int x){
    cnt.clear();
    
    for(int i=x;i<n;i++){
        cnt[a[i]]++;
    }
    for(int i=x;i<n;i++){
        if(fine()) return true;
        cnt[a[i]]--;
        cnt[a[i-x]]++;
    }
    if(fine()) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    ll lo = 0, hi = n, mid, ans = n;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    cout << ans << "\n";
    return 0;
}
