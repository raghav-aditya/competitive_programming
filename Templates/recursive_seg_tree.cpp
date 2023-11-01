#include <bits/stdc++.h>
using namespace std ;

class T {
public:
    int st, en;
    int value;
    T *left  = nullptr ; 
    T *right = nullptr ;
    int lazy = 0 ;

    T(int st_, int en_){
        this->st = st_ ; 
        this->en = en_ ;
    }
};

class SegmentTree {


public:
    SegmentTree(const vector<int>& arr) {
        root = build(0, arr.size() - 1, arr);
    }
    void update(int l, int r, int del) {
        update(root, l, r, del);
    }

    int query(int l, int r) {
        return query(root, l, r);
    }


private:
    T *root;

    T* build(int st, int en, const vector<int>& arr) 
    { 
        if (st > en) return nullptr;
        
        T* node = new T(st, en);

        if (st == en) 
            node->value = arr[st];
        else {
            int mid = (st + en) / 2;
            node->left = build(st, mid, arr);
            node->right = build(mid + 1, en, arr);
            pull(node);
        }
        return node;
    }

    void update(T* node, int l , int r , int del) 
    {
        if (node == nullptr || l > node->en || r < node->st) {
            return;
        }

        if (l <= node->st && node->en <= r ) 
        {
            node->lazy += del;
            push(node);
        }
        else 
        {
            push(node);
            update(node->left, l, r, del);
            update(node->right, l, r, del);
            pull(node);
        }
    }    

    int query(T* node, int l, int r) 
    {
        push(node);
        if (node == nullptr || l > node->en || r < node->st) {
            return 0;
        }
        if (l <= node->st && node->en <= r) {
            return node->value;
        }

        return query(node->left, l, r) + query(node->right, l, r);
    }


    void push(T* node) {
        if ( node && node->lazy != 0) {

            node->value += node->lazy * (node->en - node->st + 1);

            if (node->left )  node->left->lazy += node->lazy;
            if (node->right) node->right->lazy += node->lazy;

            node->lazy = 0;
        }
    }

    void pull( T * node ){
        node->value = node->left->value + node->right->value ;
    }

};