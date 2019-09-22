/* 
 * Author: aps
 * Time: 2019-07-28 19:43:46
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

ll dp[N][13];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = (int)s.length();

    dp[0][0] = 1LL;
    for(int i=0;i < n;i++){
        if(s[i] == '?'){
            for(int d=0;d<10;d++){
                for(int pd=0; pd < 13; pd++){
                    int rem = (pd*10 + d)%13;
                    dp[i+1][rem] = add(dp[i+1][rem],dp[i][pd]);
                }
            }
        } else {
            int d = s[i] - '0';
            for(int pd = 0; pd < 13; pd++){
                int rem = (pd*10 + d)%13;
                dp[i+1][rem] = add(dp[i+1][rem],dp[i][pd]);
            }
        }
    }

    cout << dp[n][5] << endl;
    return 0;
}
