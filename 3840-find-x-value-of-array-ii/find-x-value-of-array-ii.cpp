class Solution {
public:
    struct Node {
        long long cnt[5] = {};
        int prod = 1;
    };

    int K;
    int n;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {
        Node res;

        res.prod = (left.prod * right.prod) % K;

        // Prefix completely inside left
        for (int r = 0; r < K; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Whole left + prefix of right
        for (int r = 0; r < K; r++) {

            int newRem =
                (left.prod * r) % K;

            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }


    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {
            int rem = nums[l] % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);

        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }


    void update(int node, int l, int r,
                int idx, int value) {

        if (l == r) {

            // Reset node
            tree[node] = Node();

            int rem = value % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node,
                   l,
                   mid,
                   idx,
                   value);
        }
        else {
            update(2 * node + 1,
                   mid + 1,
                   r,
                   idx,
                   value);
        }

        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }


    // Query [ql, n-1]
    Node query(int node, int l, int r,
               int ql) {

        // Entire segment is inside query
        if (l >= ql) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        // Entire query is on right
        if (ql > mid) {
            return query(2 * node + 1,
                         mid + 1,
                         r,
                         ql);
        }

        // Query contains part of left
        // and ALL of right
        Node left =
            query(2 * node,
                  l,
                  mid,
                  ql);

        return mergeNode(
            left,
            tree[2 * node + 1]
        );
    }


    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        K = k;
        n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Point update
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Query suffix [start, n-1]
            Node result =
                query(
                    1,
                    0,
                    n - 1,
                    start
                );

            ans.push_back(
                (int)result.cnt[x]
            );
        }

        return ans;
    }
};