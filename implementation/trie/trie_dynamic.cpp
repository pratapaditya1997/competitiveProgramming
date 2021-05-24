#include<bits/stdc++.h>
using namespace std;

const ALPHA_SIZE = 255; // size of the alphabet

// trie node
struct node {
	node* edges[ALPHA_SIZE] = {};
	int words_count = 0;     // count of words sharing this node
	int words_end_count = 0; // count of words ending at this node
};


// trie class to insert, erase, search for words
class trie {
	node* root;
	int nodes_count;
	int distinct_words_count;

public:
	trie() {
		root = new node();
		nodes_count = distinct_words_count = 0;
	}

	~trie() {
		destroy(root);
	}

	// clear and removes all the words in the trie
	void clear() {
		destroy(root);
		root = new node();
		nodes_count = distinct_words_count = 0;
	}

	void insert(const char* str) {
		node* cur = root;
		for (int i=0; str[i]; ++i) {
			cur->words_count++;
			if (cur->edges[str[i]] == nullptr) {
				cur->edges[str[i]] = new node();
				nodes_count++;
			}
			cur = cur->edges[str[i]];
		}

		cur->words_count++;
		cur->words_end_count++;
		if (cur->words_end_count == 1) distinct_words_count++;
	}

	void erase(const char* str) {
		node* cur = root;
		for (int i=0; str[i]; ++i) {
			cur->words_count--;
			node* nxt = (cur->edges[str[i]]);

			if (nxt->words_count == 1) {
				destroy(nxt);
				distinct_words_count--;
				cur->edges[str[i]] = nullptr;
				return;
			}
			cur = nxt;
		}

		cur->words_count--;
		cur->words_end_count--;
	}

	int search(const char* str) const {
		node* cur = reach(str);
		return cur != nullptr ? cur->words_end_count : 0;
	}

	int getPrefixCount(const char* str) const {
		node* cur = reach(str);
		return cur != nullptr ? cur->words_count : 0;
	}

	int getDistinctWords() const {
		return distinct_words_count;
	}

private:
	node* reach(const char* str) const {
		node* cur = root;
		for (int i=0; str[i]; ++i) {
			node* nxt = cur->edges[str[i]];
			if (nxt == nullptr) return nullptr;
			cur = nxt;
		}
		return cur;
	}

	void destroy(node* root) {
		if (root == nullptr) return;
		for (int i=0; i<ALPHA_SIZE; ++i) {
			destroy(root->edges[i]);
		}
		nodes_count--;
		delete root;
	}
};