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

class BinaryDistance {
  public:
  int depth(int n) {
      int ret = 0;
      while(n != 1) {
          ret++;
          n /= 2;
      }
      return ret;
  }
  
  bool isLeft(int n) {
      while(n >= 4) n /= 2;
      return (n == 2);
  }

  int maxDist(int n, int v) {
      if(v == 1) return depth(n);
      if(isLeft(v) && isLeft(n)) return depth(v) + depth(n) - 1;
      return depth(v) + depth(n);
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int N                     = 6;
			int V                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 6;
			int V                     = 6;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			int V                     = 4;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 2;
			int V                     = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1000000000;
			int V                     = 1;
			int expected__            = 29;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 20;
			int V                     = 7;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int N                     = 12;
			int V                     = 4;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int N                     = ;
			int V                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int V                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int N                     = ;
			int V                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinaryDistance().maxDist(N, V);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
