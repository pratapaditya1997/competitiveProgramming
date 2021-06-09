#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // total length of all strings
const int ALPHA_SIZE = 26; // size of the alphabet

int trie[N][ALPHA_SIZE];
int nodes_count;
int distinct_words_count; // number of distinct words in the trie
int words_count[N];       // number of words sharing node i
int words_end_count[N];   // number of words ending at node i

void init() {
	nodes_count = 0;
	distinct_words_count = 0;
	memset(trie, -1, sizeof trie);
	memset(words_count, 0, sizeof words_count);
	memset(words_end_count, 0, sizeof words_end_count);
}

int addEdge(int node, char c) {
	int nxt = trie[node][c - 'a'];
	if (nxt == -1) {
		nxt = ++nodes_count;
		trie[node][c - 'a'] = nxt;
	}
	return nxt;
}

void insert(const string str) {
	int cur = 0;
	for (char c: str) {
		words_count[cur]++;
		cur = addEdge(cur, c);
	}

	words_count[cur]++;
	words_end_count[cur]++;
	if (words_end_count[cur] == 1) distinct_words_count++;
}

void erase(const string str) {
	int cur = 0;
	for (char c: str) {
		words_count[cur]--;
		int nxt = trie[cur][c - 'a'];
		if (words_count[nxt] == 1) {
			trie[cur][c - 'a'] = -1;
		}
		cur = nxt;
	}

	words_count[cur]--;
	words_end_count[cur]--;
	if (words_end_count[cur] == 0) distinct_words_count--;
}

int search(const string str) {
	int cur = 0;
	for (char c: str) {
		int nxt = trie[cur][c - 'a'];
		if (nxt == -1) return 0;
		cur = nxt;
	}
	return words_end_count[cur];
}