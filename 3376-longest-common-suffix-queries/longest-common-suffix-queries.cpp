class Solution {
public:

    struct Node {

        int child[26];
        int idx;

        Node() {

            memset(child, -1, sizeof(child));

            idx = -1;
        }
    };

    vector<Node> trie;

    vector<string>* wordsPtr;

    Solution() {

        trie.push_back(Node());
    }

    // Compare better answer
    bool better(int a, int b, vector<string>& words) {

        if(b == -1) return true;

        if(words[a].size() < words[b].size()) return true;

        if(words[a].size() == words[b].size() && a < b)
            return true;

        return false;
    }

    void insert(string &word, int idx,
                vector<string>& wordsContainer) {

        int node = 0;

        // Update root
        if(better(idx, trie[node].idx, wordsContainer)) {

            trie[node].idx = idx;
        }

        // Reverse traversal
        for(int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if(trie[node].child[ch] == -1) {

                trie[node].child[ch] = trie.size();

                trie.push_back(Node());
            }

            node = trie[node].child[ch];

            if(better(idx, trie[node].idx, wordsContainer)) {

                trie[node].idx = idx;
            }
        }
    }

    int search(string &word) {

        int node = 0;

        for(int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if(trie[node].child[ch] == -1)
                break;

            node = trie[node].child[ch];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for(int i = 0; i < wordsContainer.size(); i++) {

            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for(string &q : wordsQuery) {

            ans.push_back(search(q));
        }

        return ans;
    }
};