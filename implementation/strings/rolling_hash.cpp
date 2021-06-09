#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll p = 31;
const ll m = 1e9 + 9;

inline ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
}

ll power(ll a, ll p) {
    ll res = 1;
    for (; p; p/=2) {
        if (p&1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

inline ll inv(ll a) {
    return power(a, mod-2);
}

void compute_pows(vector<ll>& p_pow, vector<ll>& ip_pow, int n) {
    p_pow[0] = 1;
    for (int i=1; i<n; ++i) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
        ip_pow[i] = inv(p_pow[i]);
    }
}

ll get_hash(int l, int r, vector<ll>& ip_pow, vector<ll>& h) {
    ll res = (h[r] - h[l-1] + mod) % mod;
    res = mul(res, ip_pow[l]);
    return res % mod;
}

ll compute_hash(string const& s) {
	ll hash_value = 0;
	ll p_pow = 1;
	for (char c: s) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}