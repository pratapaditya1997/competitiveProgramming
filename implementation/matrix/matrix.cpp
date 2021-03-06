/* 
 * Author: aps
 * Time: 2019-10-30 15:10:48
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
    vector<vector<T>> d;
    int n,m;

    matrix() { n = m = 0; }

    matrix(int _n, int _m): n(_n), m(_m) {
        d = vector<vector<T>> (n, vector<T>(m, 0));
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
            for(int j=0; j<mat.m; j++) {
                for(int k=0; k<m; k++) {
                    ret.d[i][j] = add(ret.d[i][j], mul(d[i][k], mat.d[k][j]));
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

    matrix<int> a(2,3);
    matrix<int> b(3,2);

    a.d[0][0] = 1; a.d[0][1] = 2; a.d[0][2] = 3;
    a.d[1][0] = 4; a.d[1][1] = 5; a.d[1][2] = 6;

    b.d[0][0] = 7; b.d[0][1] = 8;
    b.d[1][0] = 9; b.d[1][1] = 10;
    b.d[2][0] = 11; b.d[2][1] = 12;

    matrix<int> res = a * b;
    vvi resVec = res.toVec();

    for(int i=0; i<sz(resVec); i++) {
        for(int j=0; j < sz(resVec[0]); j++) cout << resVec[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
