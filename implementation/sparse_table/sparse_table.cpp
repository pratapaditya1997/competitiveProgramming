/* 
 * Author: aps
 * Time: 2019-07-13 21:30:34
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
const int M = 20;

int n;
int a[N];

int table[M][N], logs[N];

void computeLogs() {
    for(int i = 2; i <= n; i++) {
        logs[i] = logs[i/2] + 1;
    }
}

void buildSparseTable() {
    for(int i = 0; i <= logs[n]; i++){
        int curLen = (1<<i);
        for(int j = 0; j + curLen <= n; j++) {
            if(curLen == 1) table[i][j] = a[j];
            else {
                table[i][j] = min(table[i-1][j],table[i-1][j+(curLen/2)]);
            }
        }
    }
}

int getMin(int l,int r){
    int p = logs[r-l+1];
    int pLen = (1<<p);
    return min(table[p][l],table[p][r-pLen+1]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    computeLogs();
    buildSparseTable();

    int qn; cin >> qn;

    for(int i = 0; i < qn; i++) {
        int l,r; cin >> l >> r;
        cout << getMin(l,r) << endl;
    }

    return 0;
}
