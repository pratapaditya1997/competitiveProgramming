/* 
 * Author: aps
 * Time: 2019-10-30 18:32:23
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
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

template<class T>
struct matrix {
    T** d;
    int n,m;

    matrix() { n = m = 0; }

    matrix(int _n, int _m) {
        n = _n, m = _m;
        d = new T*[n];
        for(int i=0; i<n; i++) {
            d[i] = new T[m];
            for(int j=0; j<m; j++) d[i][j] = 0;
        }
    }

    matrix(const vector<vector<T>>& v) : matrix(sz(v), sz(v[0])) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) d[i][j] = v[i][j];
        }
    }

    vector<vector<T>> toVec() {
        auto ret = vector<vector<T>>(n, vector<T>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) ret[i][j] = d[i][j];
        }
        return ret;
    }

    matrix operator + (const matrix& mat) {
        matrix ret(n,m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ret.d[i][j] = add(d[i][j], mat.d[i][j]);
            }
        }
        return ret;
    }

    matrix operator * (const matrix& mat) {
        matrix ret(n, mat.m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                for(int k=0; k<mat.m; k++) {
                    ret.d[i][k] = add(ret.d[i][k], mul(d[i][j], mat.d[j][k]));
                }
            }
        }
        return ret;
    }

    matrix operator ^ (ll p) {
        matrix ret(n,n), base(*this);
        for(int i=0; i<n; i++) ret.d[i][i] = 1;

        for(; p; p /= 2) {
            if(p&1) ret = ret * base;
            base = base * base;
        }
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll n; int m;
    cin >> n >> m;

    // transformation matrix T
    matrix<int> mat = matrix<int>(m,m);
    for(int i=0; i<m-1; i++) mat.d[i][i+1] = 1;
    mat.d[m-1][0] = mat.d[m-1][m-1] = 1;

    // initial vector F
    vi f(m,1); f[m-1]++;

    // Fn = T^(n-1) * F1
    mat = mat ^ (n-1);
    vi res(m, 0);
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            res[i] = add(res[i], mul(mat.d[i][j], f[j]));
        }
    }

    cout << res[0] << endl;

    return 0;
}
