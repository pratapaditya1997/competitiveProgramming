/* 
 * Author: aps
 * Time: 2019-08-17 22:13:01
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

const int N = 1e4+4;
int cnt[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        fill(cnt,cnt+N,0);

        int mini = N, maxi = 1, x;
        for(int i=0;i<4*n;i++){
            cin >> x;
            cnt[x]++;
            mini = min(mini,x);
            maxi = max(maxi,x);
        }

        x = mini * maxi;

        bool ok = true;
        int total = 0;
        for(int i=1;i<=sqrt(x);i++){
            if(x%i == 0){
                int j = x/i;
                if(i == j){
                    if(cnt[i] % 4 == 0){
                        total += cnt[i];
                    } else ok = false;
                    continue;
                }
                if(j >= N) continue;
                if(cnt[i] == cnt[j] && cnt[i] % 2 == 0 && cnt[j] % 2 == 0){
                    total += cnt[i] + cnt[j];
                } else ok = false;
            }
        }

        if(ok && total == 4*n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
