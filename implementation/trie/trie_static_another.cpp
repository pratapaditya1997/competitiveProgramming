int nodes;
vector<vector<int>> trie;
vector<int> words_end, words_count;

void init(int len) {
    nodes = 0;
    words_end.assign(len, 0);
    words_count.assign(len, 0);
    trie = vector<vector<int>>(len, vector<int>(26, -1));
}

// somewhere in main method, calculate total length of all words
int total_len = 0;
for (auto& word: words) total_len += word.length();