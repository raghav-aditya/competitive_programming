#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    int lazy;  // Lazy update value

    TreeNode() : value(0), lazy(0) {}
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, TreeNode());
        build(0, 0, n - 1, arr);
    }

    void update(int left, int right, int value) {
        update(0, 0, n - 1, left, right, value);
    }

    int get(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

private:
    vector<TreeNode> tree;
    int n;

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node].value = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);
        tree[node].value = tree[2 * node + 1].value + tree[2 * node + 2].value;
    }

    void propagate(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            tree[node].value += (end - start + 1) * tree[node].lazy;
            if (start != end) {
                tree[2 * node + 1].lazy += tree[node].lazy;
                tree[2 * node + 2].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int left, int right, int value) {
        propagate(node, start, end);

        if (start > right || end < left) return;
        if (start >= left && end <= right) {
            tree[node].lazy += value;
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, left, right, value);
        update(2 * node + 2, mid + 1, end, left, right, value);
        tree[node].value = tree[2 * node + 1].value + tree[2 * node + 2].value;
    }

    int query(int node, int start, int end, int left, int right) {
        propagate(node, start, end);

        if (start > right || end < left) return 0;
        if (start >= left && end <= right) return tree[node].value;

        int mid = (start + end) / 2;
        int leftResult = query(2 * node + 1, start, mid, left, right);
        int rightResult = query(2 * node + 2, mid + 1, end, left, right);
        return leftResult + rightResult;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segTree(arr);

    // Update the range [1, 3] by adding 2 to each element.

    int sum = segTree.get(1, 4);

    cout << "Sum in the range [1, 4]: " << sum << endl;

    segTree.update(1, 3, 2);

    // Query the range [1, 4] to get the sum.
     sum = segTree.get(1, 4);
    cout << "Sum in the range [1, 4]: " << sum << endl;

    return 0;
}
