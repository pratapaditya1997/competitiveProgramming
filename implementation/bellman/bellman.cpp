/* 
 * Author: aps
 * Time: 2019-10-28 14:26:50
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

struct edge {
    int from, to, cost;
};

int n,m,v;
vector<edge> e;
vi d, p;

/**
* vertex y either lies in the -ve cycle or it is reachable from it
* to get vertices that are guaranteed to be the in the -ve cycle, starting from vertex y
* pass through the parents n times
*/
void cyclePresent(int y) {
    for(int i=0; i<n; i++) y = p[y];

    vi path;
    for(int cur=y; ; cur=p[cur]) {
        path.push_back(cur);
        if(cur == y && path.size() > 1) break;
    }
    reverse(all(path));

    cout << "negative cycle: \n";
    for(int i=0; i<(int)path.size(); i++) {
        cout << path[i] << " ";
    }
}

void bellman(int src) {
    d.assign(n, mod);
    p.assign(n, -1);
    d[src] = 0;

    int x = -1;
    for(int i=0; i<n; i++) {
        x = -1;
        for(int j=0; j<m; j++) {
            if(d[e[j].from] < mod) {
                if(d[e[j].to] > d[e[j].from] + e[j].cost) {
                    d[e[j].to] = min(d[e[j].to], d[e[j].from] + e[j].cost);
                    p[e[j].to] = e[j].from;
                    x = e[j].to;
                }
            }
        }
    }
    if(x != -1) {
        // cycle is present
        cyclePresent(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int from, to, cost; cin >> from >> to >> cost;
        e.push_back({from, to, cost});
    }

    bellman(0);
    return 0;
}
