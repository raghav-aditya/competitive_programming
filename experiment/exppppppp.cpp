#include <iostream>
#include <vector>

class SegmentTreeNode {
public:
    int start, end, data;
    int lazy;

    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int start_, int end_)
        : start(start_), end(end_), data(0), lazy(0), left(nullptr), right(nullptr) {}

    ~SegmentTreeNode() {
        delete left;
        delete right;
    }
};

class SegmentTree {
private:
    SegmentTreeNode* root;

public:
    SegmentTree(const std::vector<int>& arr) {
        root = build(0, arr.size() - 1, arr);
    }

    SegmentTreeNode* build(int start, int end, const std::vector<int>& arr) {
        if (start > end)
            return nullptr;

        SegmentTreeNode* node = new SegmentTreeNode(start, end);

        if (start == end) {
            node->data = arr[start];
        } else {
            int mid = (start + end) / 2;
            node->left = build(start, mid, arr);
            node->right = build(mid + 1, end, arr);
            node->data = node->left->data + node->right->data;
        }

        return node;
    }

    void propagateLazy(SegmentTreeNode* node) {
        if (node->lazy != 0) {
            node->data += (node->end - node->start + 1) * node->lazy;

            if (node->start != node->end) {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }

            node->lazy = 0;
        }
    }

    void updateRange(SegmentTreeNode* node, int l, int r, int val) {
        if (node == nullptr || node->start > r || node->end < l)
            return;

        if (node->start >= l && node->end <= r) {
            node->data += (node->end - node->start + 1) * val;

            if (node->start != node->end) {
                node->left->lazy += val;
                node->right->lazy += val;
            }
        } else {
            propagateLazy(node);
            updateRange(node->left, l, r, val);
            updateRange(node->right, l, r, val);
            node->data = node->left->data + node->right->data;
        }
    }

    void updateRange(int l, int r, int val) {
        updateRange(root, l, r, val);
    }

    int query(SegmentTreeNode* node, int l, int r) {
        if (node == nullptr || node->start > r || node->end < l)
            return 0;

        if (node->start >= l && node->end <= r) {
            return node->data;
        } else {
            propagateLazy(node);
            int leftSum = query(node->left, l, r);
            int rightSum = query(node->right, l, r);
            return leftSum + rightSum;
        }
    }

    int query(int l, int r) {
        return query(root, l, r);
    }

    ~SegmentTree() {
        delete root;
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    // Query range [0, 3] before any updates
    std::cout << "Sum in range [0, 3]: " << st.query(0, 3) << std::endl;

    // Update range [0, 3] with value 2
    st.updateRange(0, 3, 2);

    // Query range [0, 3] after update
    std::cout << "Sum in range [0, 3]: " << st.query(0, 3) << std::endl;

    return 0;
}
