/* 
 * Author: aps
 * Time: 2019-08-04 00:17:39
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

const int N = 1e5+5;

ll t[4*N], lazy[4*N], a[N], n;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void push(int v){
    t[v*2] += lazy[v];
    t[v*2+1] += lazy[v];

    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    if(l > r) return;
    if(l == tl && tr == r){
        t[v] += val;
        lazy[v] += val;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2,tl,tm,l,min(r,tm),val);
        update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if(l > r) return -inf;
    if(l <= tl && tr <= r){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    ll ret1 = query(v*2,tl,tm,l,min(r,tm));
    ll ret2 = query(v*2+1,tm+1,tr,max(l,tm+1),r);
    return max(ret1,ret2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    build(1,0,n-1);

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1) {
            int l, r, x; cin >> l >> r >> x;
            update(1,0,n-1,l,r,x);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1,0,n-1,l,r) << endl;
        }
    }

    return 0;
}
