#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
	int n = s.length();
	vector<int> pi(n, 0);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j>0 && s[i] != s[j]) {
			j = pi[j-1];
		}
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}
	return pi;
}

int main () {
	return 0;
}

/**
* idea is to create new string such that 
* new_string = s + # + reverse(s)
* now run KMP over this new string and pi[new_lenth - 1] will give us the answer
*/
int get_longest_prefix_palindrome(string s) {
	string rev = s;
    reverse(rev.begin(), rev.end());
    string t = s + "#" + rev;

    vector<int> pi = prefix_function(t);
    return pi[t.length() - 1];
}