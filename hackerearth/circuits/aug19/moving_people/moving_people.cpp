/* 
 * Author: aps
 * Time: 2019-08-29 21:31:41
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

const int N = 1005;

int n,m, a[N][N], sum[N][N];
int l,t,r,b,ans;
int sx,sy,dx,dy;

bool doneWithItAlready = false;

void preCalc() {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
}

void print() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) cout << sum[i][j] << " ";
        cout << "\n";
    }
}

void moveUp(int del) {
    b += del;
    int mini = min(t,del);
    t -= mini;
    del -= mini;

    if(del == 0) return;
    sx += del;
    if(sx > dx) doneWithItAlready = true;
}

void moveDown(int del) {
    t += del;
    int mini = min(b,del);
    b -= mini;
    del -= mini;

    if(del == 0) return;
    dx -= del;
    if(dx < sx) doneWithItAlready = true;
}

void moveLeft(int del) {
    r += del;
    int mini = min(l,del);
    l -= mini;
    del -= mini;

    if(del == 0) return;
    sy += del;
    if(sy > dy) doneWithItAlready = true;
}

void moveRight(int del) {
    //cout << "before move right \n";
    //cout << sx << "," << sy << " " << dx << "," << dy << "\n";
    l += del;
    int mini = min(r,del);
    r -= mini;
    del -= mini;

    if(del == 0) return;
    dy -= del;
    if(dy < sy) doneWithItAlready = true;
    //cout << sx << "," << sy << " " << dx << "," << dy << "\n";
}

void cleanUp() {
    if(sx <= 0) sx = 1;
    if(sy <= 0) sy = 1;
    if(dx >= n) dx = n;
    if(dy >= m) dy = m;
}

int query() {
    //cout << sx << " " << sy << " , " << dx << " " << dy << "\n";
    if((sx <= 0 && dx <= 0) || (sy <= 0 && dy <= 0)) return 0;
    dx = min(dx,n);
    dy = min(dy,m);
    if(sx <= 0) sx = 1;
    if(sy <= 0) sy = 1;
    //cout << sx << " " << sy << " , " << dx << " " << dy << "\n"; 
    return sum[dx][dy] - sum[dx][sy-1] - sum[sx-1][dy] + sum[sx-1][sy-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> n >> m >> q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch; cin >> ch;
            if(ch == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    preCalc();

    ans = a[n][m];
    sx = 1, sy = 1, dx = n, dy = m;
    l = t = r = b = 0;

    //cout << "total " << query() << "\n"; 

    while(q--){
        int type; cin >> type;

        if(doneWithItAlready) {
            cout << 0 << "\n";
            continue;
        }

        if(type == 1) {
            int x,y; cin >> x >> y;
            if(x < 0) {
                moveRight(abs(x));
                if(doneWithItAlready) {
                    cout << 0 << "\n";
                    continue;
                }
                cleanUp();
            }
            if(x > 0) {
                moveLeft(x);
                if(doneWithItAlready) {
                    cout << 0 << "\n";
                    continue;
                }
                cleanUp();
            }
            if(y < 0) {
                moveDown(abs(y));
                if(doneWithItAlready) {
                    cout << 0 << "\n";
                    continue;
                }
                cleanUp();
            }
            if(y > 0) {
                moveUp(y);
                if(doneWithItAlready) {
                    cout << 0 << "\n";
                    continue;
                }
                cleanUp();
            }
        } else {
            if(doneWithItAlready) {
                cout << 0 << "\n";
                continue;
            }
            cout << query() << "\n";
            cleanUp();
        }

        //cout << "after q: " << q << " (" << sx << "," << sy << ") (" << dx << "," << dy << ") ";
        //cout << " l: " << l << " r: " << r << " t: " << t << " b: " << b << "\n";  
    }

    return 0;
}
