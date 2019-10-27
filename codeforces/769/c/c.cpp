/* 
 * Author: aps
 * Time: 2019-10-27 18:13:56
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
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
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

char dir[4] = {'D','L','R','U'};
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m,k; cin >> n >> m >> k;
    if(k&1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<vector<bool>> grid(n, vector<bool>(m));
    vector<vi> dist(n, vi(m,-1));
    pii src;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch; cin >> ch;
            if(ch == 'X') src = {i,j};
            grid[i][j] = (ch != '*');
        }
    } 

    queue<pii> q;
    q.push(src);
    dist[src.fi][src.se] = 0;

    auto inValid = [&](pii p) -> bool {
        if(p.fi < 0 || p.fi >= n || p.se < 0 || p.se >= m || !grid[p.fi][p.se]) {
            return true;
        }
        return false;
    };

    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            pii nxt = {cur.fi + dx[i], cur.se + dy[i]};
            if(inValid(nxt) || dist[nxt.fi][nxt.se] != -1) {
                continue;
            }
            dist[nxt.fi][nxt.se] = dist[cur.fi][cur.se] + 1;
            q.push(nxt);
        }
    }

    string ans = "";
    pii cur = src;
    for(int i = k; i > 0; i--) {
        for(int j = 0; j < 4; j++) {
            pii nxt = {cur.fi + dx[j], cur.se + dy[j]};
            if(inValid(nxt)) continue;
            if(dist[nxt.fi][nxt.se] >= i) continue;
            ans += dir[j];
            cur = nxt;
            break;
        }
    }

    if(ans.length() != k) cout << "IMPOSSIBLE" << "\n";
    else cout << ans << "\n";

    return 0;
}
