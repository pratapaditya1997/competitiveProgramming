#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // elements in the array
int n, t[4*N];         // 4*N = size of the segment tree

/**
* v - index of the current vertex
* [tl, tr] - boundaries of the current segment
*/
void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}

	int tm = (tl + tr) / 2;
	build(v*2, tl, tm);
	build(v*2 + 1, tm + 1, tr);

	t[v] = t[v*2] + t[v*2 + 1];
}

/**
* v - index of the current vertex
* [tl, tr] - boundaries of the current segment
* [l, r] - boundaries of the query
*/
int sum(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v];
	
	int tm = (tl + tr) / 2;
	return sum(v*2, tl, tm, l, min(r, tm))
			+ sum(v*2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

/**
* v - index of the current vertex
* [tl, tr] - boundaries of the current segment
* [l, r] - boundaries of the query
* a[pos] = new_val is the update we want to make
*/
void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = new_val;
		return;
	}

	int tm = (tl + tr) / 2;
	if (pos <= tm) update(v*2, tl, tm, pos, new_val);
	else update(v*2 + 1, tm + 1, tr, pos, new_val);

	t[v] = t[v*2] + t[v*2 + 1];
}

// some utility methods

/**
* find the kth element
*/
int find_kth(int v, int tl, int tr, int k) {
	if (k > t[v]) return -1;
	if (tl == tr) return tl;

	int tm = (tl + tr) / 2;
	if (t[v*2] >= k) return find_kth(v*2, tl, tm, k);
	else return find_kth(v*2 + 1, tm + 1, tr, k - t[v*2]);
}










