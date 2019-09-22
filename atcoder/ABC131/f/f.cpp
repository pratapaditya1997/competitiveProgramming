/* 
 * Author: aps
 * Time: 2019-07-14 18:12:05
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

struct DSU{
    int connected,par[N],sz[N];
    DSU(){}
    DSU(int n){ 
        for(int i=0;i<n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
        connected = n;
    }
    int root(int x) {
        while(x != par[x]) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }
    void merge(int u,int v){
        int ru = root(u), rv = root(v);
        if(ru == rv) return;
        --connected;
        if(sz[ru] > sz[rv]) swap(ru,rv);
        sz[rv] += sz[ru];
        sz[ru] = 0;
        par[ru] = par[rv];
    }
};

int n,x[N],y[N];
vi ver[N], hor[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    DSU dsu(n);
    
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        ver[x[i]].pb(i);
        hor[y[i]].pb(i);
    }

    for(int i=1;i<N;i++){
        for(int j=1;j<(int)ver[i].size();j++) {
            //cout << "merge" << ver[i][j] << " " << ver[i][j-1] << endl;
            dsu.merge(ver[i][j],ver[i][j-1]);
        }
        for(int j=1;j<(int)hor[i].size();j++) {
            //cout << "merge" << hor[i][j] << " " << hor[i][j-1] << endl;
            dsu.merge(hor[i][j],hor[i][j-1]);
        }
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
        //cout << i << " " << dsu.root(i) << " " << dsu.par[i] << endl;
        if(dsu.root(i) == i){
            set<int> allX,allY;
            for(int j=0;j<n;j++){
                if(dsu.root(j) == i) {
                    allX.insert(x[j]);
                    allY.insert(y[j]);
                }
            }
            //cout << i << " " <<  allX.size() << " " << allY.size() << endl;
            ans += 1LL * (ll)allX.size() * (ll)allY.size();
        }
    }

    cout << ans - n << endl;

    return 0;
}
