/* 
 * Author: aps
 * Time: 2019-08-03 19:36:18
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

int logs[N], cnt[N];

void computeLogs(){
    for(int i=2;i<N;i++){
        int p = i/2;
        if(i & 1) ++p;
        logs[i] = logs[p] + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    computeLogs();

    int n,I; cin >> n >> I;
    I *= 8;

    vi a(n), b(n);
    map<int,int> mp;

    int k = 1;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));

    for(int i=0;i<n;i++){
        if(mp.find(b[i]) == mp.end()){
            mp[b[i]] = k++;
        }
    }

    for(int i=0;i<n;i++){
        a[i] = mp[a[i]];
        cnt[a[i]]++;
    }

    int l = 1, r = 1, change = n - cnt[1], ans = n, cost = 0;
    while(1){
        if(l>r || r >= k) break;
        int bitsNeeded = logs[r-l+1];
        cost = bitsNeeded * n;
        
        if(cost <= I){
            ans = min(ans,change);
            r += 1;
            change -= cnt[r];
        } else {
            change += cnt[l];
            l += 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}
