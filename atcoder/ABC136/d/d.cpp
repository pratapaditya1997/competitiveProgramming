/* 
 * Author: aps
 * Time: 2019-08-13 19:02:24
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
    
    string s; cin >> s;
    int n = s.length();

    int cnt[n], pos[n];
    fill(cnt,cnt+n,0);
    fill(pos,pos+n,0);

    int x = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'L') pos[i] = x;
        else x = i;
    }

    x = n-1;
    for(int i=n-1; i>=0 ; i--){
        if(s[i] == 'R') pos[i] = x;
        else x = i;
    }

    for(int i=0;i<n;i++){
        if(s[i] == 'L'){
            x = i - pos[i];
            if(x&1) cnt[pos[i]+1]++;
            else cnt[pos[i]]++;
        } else {
            x = pos[i] - i;
            if(x&1) cnt[pos[i]-1]++;
            else cnt[pos[i]]++;
        }
    }

    for(int i=0;i<n;i++) cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
