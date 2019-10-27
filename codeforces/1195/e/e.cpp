/* 
 * Author: aps
 * Time: 2019-07-21 20:10:25
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

const int N = 3003;

ll n,m,a,b,g,x,y,z;
ll mat[N][N],mn[N][N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m >> a >> b;
    cin >> g >> x >> y >> z;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mat[i][j] = g;
            g = (g*x+y) % z;
        }
    }

    deque<ll> q;
    for(int i=1;i<=n;i++){
        while(!q.empty()) q.pop_back();
        for(int j=1;j<=m;j++){
            while(!q.empty() && q.front() <= j-b) q.pop_front();
            while(!q.empty() && mat[i][q.back()] >= mat[i][j]) q.pop_back();
            q.push_back(j);
            if(j >= b) mn[i][j] = mat[i][q.front()];
        }
    }

    ll ans = 0;
    for(int j=b;j<=m;j++){
        while(!q.empty()) q.pop_back();
        for(int i=1;i<=n;i++){
            while(!q.empty() && q.front() <= i-a) q.pop_front();
            while(!q.empty() && mn[q.back()][j] >= mn[i][j]) q.pop_back();
            q.push_back(i);
            if(i >= a) ans += mn[q.front()][j];
        }
    }

    cout << ans << endl;

    return 0;
}
