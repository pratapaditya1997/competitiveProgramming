#include<bits/stdc++.h>
using namespace std;

vector<int> z_trivial(const string& s) {
	int n = s.length();
	vector<int> z(n, 0);
	for (int i=1; i<n; ++i) {
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			++z[i];
		}
	}
	return z;
}

int main() {
	return 0;
}