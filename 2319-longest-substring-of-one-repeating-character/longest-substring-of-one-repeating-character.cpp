class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int len;
        int pref;
        int suff;
        int best;

        Node() {
            leftChar = rightChar = '#';
            len = 0;
            pref = suff = best = 0;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {

        if(a.len == 0)
            return b;

        if(b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        res.best = max(a.best, b.best);

        if(a.rightChar == b.leftChar) {

            // Join suffix of left + prefix of right
            res.best = max(res.best, a.suff + b.pref);

            // Entire left segment has same character
            if(a.pref == a.len) {
                res.pref = a.len + b.pref;
            }

            // Entire right segment has same character
            if(b.suff == b.len) {
                res.suff = b.len + a.suff;
            }
        }

        return res;
    }

    void build(int node, int low, int high, string &s) {

        if(low == high) {

            seg[node].leftChar = s[low];
            seg[node].rightChar = s[low];

            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;

            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * node + 1, low, mid, s);
        build(2 * node + 2, mid + 1, high, s);

        seg[node] = merge(
            seg[2 * node + 1],
            seg[2 * node + 2]
        );
    }

    void update(int node, int low, int high,
                int index, char ch) {

        if(low == high) {

            seg[node].leftChar = ch;
            seg[node].rightChar = ch;

            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;

            return;
        }

        int mid = low + (high - low) / 2;

        if(index <= mid) {
            update(2 * node + 1, low, mid, index, ch);
        }
        else {
            update(2 * node + 2, mid + 1, high, index, ch);
        }

        seg[node] = merge(
            seg[2 * node + 1],
            seg[2 * node + 2]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n - 1, index, ch);

            ans.push_back(seg[0].best);
        }

        return ans;
    }
};