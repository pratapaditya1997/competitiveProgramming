#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// counting sort of array p by values in array c
void count_sort(vector<int>& p, vector<int>& c) {
    int n = size(p);
    vector<int> cnt(n);
    for(auto x: c) cnt[x]++;
    vector<int> p_new(n);
    vector<int> pos(n, 0);
    for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
    for(auto x: p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string s; cin >> s;
    s += "$";
    int n = s.length();
    vector<int> p(n), c(n);
    {
        // k = 0
        vector<pair<char,int>> a(n);
        for(int i=0; i<n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for(int i=0; i<n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; i++) {
            if(a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    while((1<<k) < n) {
        // k -> k+1

        // prepend 2^k characters to make substring of length 2^k+1 
        // with 2nd half already sorted
        for(int i=0; i<n; i++) {
            p[i] = (p[i] - (1<<k) + n) % n;
        }

        // sort first half using the array c
        count_sort(p, c);

        // generate new equivalence class array c_new using prev array c
        vector<int> c_new(n, 0);
        pair<int,int> prev, cur;
        for(int i=1; i<n; i++) {
            prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
            cur  = {c[p[i]], c[(p[i] + (1<<k))%n]};
            if(prev == cur) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }

    for(int i=0; i<n; i++) cout << p[i] << " ";
    return 0;
}
