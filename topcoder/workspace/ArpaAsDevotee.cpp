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

class ArpaAsDevotee {
    public:
    bool isInvalid(vector<pii> v) {
        int n = (int)v.size();
        
        for(int i=0; i<n; i++) {
            if(i) {
                if(v[i].fi == v[i-1].fi) {
                    if(v[i].se != v[i-1].se) return true;
                }
            }
            if(v[i].se > v[i].fi) return true;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(v[i].se == v[j].se || v[j].se > v[i].fi);
                else return true;
            }
        }
        return false;
    }

    vector <string> solve(int n, int q, vector <int> a, vector <int> lastSeen, vector <int> t) {
        vector<string> ret(q);
        vector<pii> v;

        for(int i=0; i<n; i++) {
            v.pb({a[i], lastSeen[i]});
        }
        sort(all(v));

        if(isInvalid(v)) return vector<string>{};

        int MX = 864001;
        vi seen(MX, 0), off(MX, 0);
        for(int i=0; i<n; i++) seen[v[i].se] = 1;
        for(int i=0; i<n; i++) {
            for(int j = v[i].se + 1; j<=v[i].fi; j++) off[j] = 1;
        }

        for(int i=0; i<q; i++) {
            if(seen[t[i]]) ret[i] = "Yes";
            if(off[t[i]]) ret[i] = "No";
            if(!seen[t[i]] && !off[t[i]]) ret[i] = "Not Sure"; 
        }

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
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			int n                     = 5;
			int q                     = 7;
			int a[]                   = {11, 13, 17, 25, 29};
			int lastSeen[]            = {11, 13, 15, 15, 29};
			int t[]                   = {11, 12, 13, 14, 15, 16, 17};
			string expected__[]       = {"Yes", "Not Sure", "Yes", "Not Sure", "Yes", "No", "No" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int q                     = 1;
			int a[]                   = {1, 10};
			int lastSeen[]            = {5, 3};
			int t[]                   = {6};
			string expected__[]       = { };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			int q                     = 1;
			int a[]                   = {7, 7, 1};
			int lastSeen[]            = {3, 5, 1};
			int t[]                   = {4};
			string expected__[]       = { };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n                     = 2;
			int q                     = 3;
			int a[]                   = {5, 5};
			int lastSeen[]            = {2, 2};
			int t[]                   = {1, 2, 3};
			string expected__[]       = {"Not Sure", "Yes", "No" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int q                     = ;
			int a[]                   = ;
			int lastSeen[]            = ;
			int t[]                   = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int q                     = ;
			int a[]                   = ;
			int lastSeen[]            = ;
			int t[]                   = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int q                     = ;
			int a[]                   = ;
			int lastSeen[]            = ;
			int t[]                   = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ArpaAsDevotee().solve(n, q, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(lastSeen, lastSeen + (sizeof lastSeen / sizeof lastSeen[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
