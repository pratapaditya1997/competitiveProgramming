/* 
 * Author: aps
 * Time: 2019-08-04 01:03:13
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

const int N = 1e6+6;

int t[4*N], lazy[4*N];

void push(int v){
    t[v*2] = max(t[v*2], lazy[v]);
    t[v*2+1] = max(t[v*2+1], lazy[v]);

    lazy[v*2] = max(lazy[v*2], lazy[v]);
    lazy[v*2+1] = max(lazy[v*2+1], lazy[v]);

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) {
        t[v] = val;
        lazy[v] = 0;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(pos <= tm) {
        update(v*2, tl, tm, pos, val);
    } else {
        update(v*2+1, tm+1, tr, pos, val);
    }
}

int query(int v, int tl, int tr, int pos){
    if(tl == tr) {
        return max(t[v], lazy[v]);
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return query(v*2, tl, tm, pos);
    else return query(v*2+1, tm+1, tr, pos);
}

void print(){
    cout << "--------------------------" << endl;
    for(int i=1;i<=7;i++){
        cout << "node: " << i << " value: " << t[i] << endl;
    }
    cout << "--------------------------" << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        update(1,0,n-1,i,x);
    }

    //print();
    
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int p, x; cin >> p >> x;
            --p;
            update(1,0,n-1,p,x);
            //print();
        } else {
            int x; cin >> x;
            lazy[1] = max(lazy[1], x);
        }
    }

    for(int i=0;i<n;i++){
        cout << query(1,0,n-1,i) << " ";
        //print();
    }
    cout << endl;
    return 0;
}
