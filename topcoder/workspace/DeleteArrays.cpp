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

class DeleteArrays {
    public:
    vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z) {
        vl A(a), B(b), C(c);
        vector<pair<ll,int>> tot;
        ll ans = 0;
        
        A[0] = 33; A[1] = 42;
        tot.pb({A[0], 1}); tot.pb({A[1], 1});
        ans += A[0] + A[1];
        for(int i=2; i<a; i++) {
            A[i] = add(5*A[i-1], 7*A[i-2]) + 1;
            ans += A[i];
            tot.pb({A[i], 1});
        }

        B[0] = 13; tot.pb({B[0], 2});
        ans += B[0];
        for(int i=1; i<b; i++) {
            B[i] = mul(11L,B[i-1]) + 1;
            ans += B[i];
            tot.pb({B[i], 2});
        }

        C[0] = 7; C[1] = 2;
        tot.pb({C[0], 3}); tot.pb({C[1], 3});
        ans += C[0] + C[1];
        for(int i=2; i<c; i++) {
            C[i] = add(5*C[i-1], 7*C[i-2]) + 1;
            ans += C[i];
            tot.pb({C[i], 3});
        }

        ll left = (a+b+c) % 3, mini = 0;
        sort(all(tot));
        for(int i=0; i<left; i++) {
            ans -= tot[i].fi;
            mini += tot[i].fi;
            switch(tot[i].se) {
                case 1:
                    --a;
                    break;
                case 2:
                    --b;
                    break;
                case 3:
                    --c;
                    break;
                default: break;
            }
        }

        vector<pii> v = {{x,1}, {y,2}, {z,3}};
        sort(all(v));
        for(int i=0; i<3; i++) {
            ll term = v[i].se;
            ll val = v[i].fi;

            switch(term) {
                case 1: {
                    int minab = min(a,b);
                    a -= minab;
                    b -= minab;
                    ans += val * minab;
                    break;
                }
                case 2: {
                    int minbc = min(b,c);
                    b -= minbc;
                    c -= minbc;
                    ans += val * minbc;
                    break;
                }
                case 3: {
                    int minac = min(a,c);
                    a -= minac;
                    c -= minac;
                    ans += val * minac;
                    break;
                }
                default: break;
            }
        }

        vl ret = {mini, ans};
        return ret;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int a                     = 2;
			int b                     = 2;
			int c                     = 2;
			long long x               = 2;
			long long y               = 3;
			long long z               = 4;
			long long expected__[]    = {0, 250};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int a                     = 3;
			int b                     = 2;
			int c                     = 2;
			long long x               = 3;
			long long y               = 2;
			long long z               = 1;
			long long expected__[]    = {2, 688};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int a                     = 4;
			int b                     = 4;
			int c                     = 4;
			long long x               = 5;
			long long y               = 6;
			long long z               = 7;
			long long expected__[]    = {0, 22620};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int a                     = 100000;
			int b                     = 5;
			int c                     = 8;
			long long x               = 424242;
			long long y               = 474747;
			long long z               = 123456789;
			long long expected__[]    = {50097960828195LL, 13989929548LL};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long x               = ;
			long long y               = ;
			long long z               = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long x               = ;
			long long y               = ;
			long long z               = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long x               = ;
			long long y               = ;
			long long z               = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = DeleteArrays().doDelete(a, b, c, x, y, z);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
