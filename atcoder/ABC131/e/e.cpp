/* 
 * Author: aps
 * Time: 2019-07-13 22:43:34
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,k; cin >> n >> k;

    int maxi = ((n-1)*(n-2))/2;
    if(k > maxi) {
        cout << -1 << endl;
    } else {
        vector<pii> ans;
        for(int i=1;i<=n-1;i++) {
            ans.pb({i,n});
        }

        int del = maxi - k;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n-1;j++){
                if(del == 0){
                    cout << (int)ans.size() << endl;
                    for(pii p: ans){
                        cout << p.fi << " " << p.se << endl;
                    }
                    return 0;
                } else {
                    ans.pb({i,j});
                    --del;
                }
            }
        }

        cout << (int)ans.size() << endl;
        for(pii p: ans) cout << p.fi << " " << p.se << endl;
    }

    return 0;
}
