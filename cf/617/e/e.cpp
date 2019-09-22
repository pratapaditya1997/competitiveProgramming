/* 
 * Author: aps
 * Time: 2019-07-14 22:55:08
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
const int MX = 3e6+6;
const int block = 320;

struct query {
    int l,r,idx;
    bool operator < (query other) const {
        if(l/block != other.l/block){
            return l/block < other.l/block;
        } else {
            return (l/block & 1) ? (r<other.r) : (r>other.r);
        }
    }
};

ll cur_ans;
int n,Q,K;
int cnt[MX],a[N];
ll ans[N];

query q[N];

void ADD(int x){
    cur_ans += cnt[x^K];
    cnt[x]++;
}

void REMOVE(int x){
    cnt[x]--;
    cur_ans -= cnt[x^K];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> Q >>  K;

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] = a[i] ^ a[i-1];
    }

    for(int i=0;i<Q;i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
        q[i].l --;
    }

    sort(q,q+Q);

    int l=1,r=0;
    for(int i=0;i<Q;i++){
        int left = q[i].l, right = q[i].r;

        while(r < right){
            r++;
            ADD(a[r]);
        }
        while(r > right){
            REMOVE(a[r]);
            r--;
        }
        while(l < left){
            REMOVE(a[l]);
            l++;
        }
        while(l > left){
            l--;
            ADD(a[l]);
        }

        ans[q[i].idx] = cur_ans;
    }

    for(int i=0;i<Q;i++) cout << ans[i] << endl;

    return 0;
}
