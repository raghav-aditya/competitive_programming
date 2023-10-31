#include <iostream>
#include <vector>

using namespace std;

class SegmentTreeNode {
public:
    int start, end;
    int value;
    SegmentTreeNode *left, *right;
    int lazy;

    SegmentTreeNode(int start, int end) : start(start), end(end), value(0), left(nullptr), right(nullptr), lazy(0) {}
};

class SegmentTree {
private:
    SegmentTreeNode *root;

public:
    SegmentTree(const vector<int>& arr) {
        root = build(0, arr.size() - 1, arr);
    }

    SegmentTreeNode* build(int start, int end, const vector<int>& arr) {
        if (start > end) return nullptr;

        SegmentTreeNode* node = new SegmentTreeNode(start, end);

        if (start == end) {
            // Leaf node, initialize from the input array
            node->value = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            node->left = build(start, mid, arr);
            node->right = build(mid + 1, end, arr);
            node->value = node->left->value + node->right->value;
        }

        return node;
    }

    void update(int start, int end, int delta) {
        update(root, start, end, delta);
    }

    void update(SegmentTreeNode* node, int start, int end, int delta) {
        if (node == nullptr || start > node->end || end < node->start) {
            return;
        }

        if (start <= node->start && node->end <= end) {
            // Update the node and mark it as lazy
            node->value += delta * (node->end - node->start + 1);
            node->lazy += delta;
        }
        else {
            // Propagate the lazy value to the children before proceeding
            pushLazy(node);
            update(node->left, start, end, delta);
            update(node->right, start, end, delta);
            node->value = node->left->value + node->right->value;
        }
    }

    int get(int start, int end) {
        return query(root, start, end);
    }

    int query(SegmentTreeNode* node, int start, int end) {
        if (node == nullptr || start > node->end || end < node->start) {
            return 0;
        }

        if (start <= node->start && node->end <= end) {
            return node->value;
        }

        pushLazy(node);
        int leftValue = query(node->left, start, end);
        int rightValue = query(node->right, start, end);

        return leftValue + rightValue;
    }

    void pushLazy(SegmentTreeNode* node) {
        if (node->lazy != 0) {
            if (node->left) {
                node->left->lazy += node->lazy;
                node->left->value += node->lazy * (node->left->end - node->left->start + 1);
            }
            if (node->right) {
                node->right->lazy += node->lazy;
                node->right->value += node->lazy * (node->right->end - node->right->start + 1);
            }
            node->lazy = 0;
        }
    }
};

int main() {
    vector<int> inputArray = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree segmentTree(inputArray);

    // Update a range [2, 5] by adding 3
    segmentTree.update(2, 5, 3);

    // Query the sum in a range [1, 6]
    int result = segmentTree.query(1, 6);
    cout << "Sum in range [1, 6]: " << result << endl;

    return 0;
}
