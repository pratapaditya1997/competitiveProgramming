/* 
 * Author: aps
 * Time: 2019-07-19 11:58:41
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
const int block = 450;

struct query {
    int l,r,idx;
    bool operator < (query other) const {
        if(l/block != other.l/block){
            return (l/block < other.l/block);
        } else {
            return (l/block & 1) ? (r < other.r) : (r > other.r);
        }
    }
};

ll cur_ans = 0;
ll cnt[N],a[N],ans[N];

query q[N];

void ADD(int x){
    int prev = cnt[x];
    cur_ans += x * (1 + 2 * prev);
    ++ cnt[x];
}

void REMOVE(int x){
    int prev = cnt[x];
    cur_ans += x * (1 - 2 * prev);
    -- cnt[x];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,t; cin >> n >> t;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=0;i<t;i++){
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }

    sort(q,q+t);

    int l=1,r=0;
    for(int i=0;i<t;i++){
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

    for(int i=0;i<t;i++) cout << ans[i] << endl;

    return 0;
}
