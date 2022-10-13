// Implementing a crit-bit tree in C++.
// This is a simple implementation of a crit-bit tree, which is a
// data structure for storing strings.  It is a binary tree, where
// each node is a bit in the string.  The tree is balanced, and
// the strings are stored in lexicographic order.

#include <bits/stdc++.h>
using namespace std;

// A crit-bit tree is a binary tree, where each node is a bit in the
// string.  The tree is balanced, and the strings are stored in
// lexicographic order.  The tree is represented by a pointer to the
// root node.  The root node is a dummy node, and the actual strings
// are stored in the children of the root node.  The root node is
// always a 0 node, and the children of the root node are always 1
// nodes.  The children of a 1 node are either 0 nodes or 1 nodes.

// Create a new node with the given bit and value.
struct node {
    int bit;
    string value;
    node *left, *right;
    node(int bit, string value) : bit(bit), value(value), left(NULL), right(NULL) {}
};

// Insert a string into the tree.  The tree is modified in place.
void insert(node *&root, string s) {
    // If the tree is empty, create a new root node.
    if (root == NULL) {
        root = new node(0, "");
        root->left = new node(1, s);
        return;
    }

    // Find the node with the highest bit that is different from the
    // string.  If there is no such node, then the string is already
    // in the tree.
    node *n = root;
    while (n->bit < s.size() && n->bit < n->value.size() && s[n->bit] == n->value[n->bit])
        n = (s[n->bit] == '0') ? n->left : n->right;
    if (n->bit >= s.size() || n->bit >= n->value.size()) return;

    // Create a new node with the bit that is different from the
    // string.  The new node will be the parent of the old node and
    // the new string.
    node *p = new node(n->bit, s);
    if (s[p->bit] == '0') {
        p->left = new node(p->bit + 1, s);
        p->right = n;
    } else {
        p->left = n;
        p->right = new node(p->bit + 1, s);
    }

    // Replace the old node with the new node.
    if (n == root) {
        root = p;
    } else {
        node *parent = root;
        while (parent->left != n && parent->right != n)
            parent = (s[parent->bit] == '0') ? parent->left : parent->right;
        if (parent->left == n)
            parent->left = p;
        else
            parent->right = p;
    }
}

// Find the string in the tree that is equal to the given string.
// If there is no such string, return NULL.
string *find(node *root, string s) {
    if (root == NULL) return NULL;
    node *n = root;
    while (n->bit < s.size() && n->bit < n->value.size() && s[n->bit] == n->value[n->bit])
        n = (s[n->bit] == '0') ? n->left : n->right;
    if (n->bit >= s.size() || n->bit >= n->value.size()) return NULL;
    return &n->value;
}

// construct a crit-bit tree from a list of strings
node *construct(vector<string> &strings) {
    node *root = NULL;
    for (string s : strings)
        insert(root, s);
    return root;
}

// print the crit-bit tree in lexicographic order
void print(node *root) {
    if (root == NULL) return;
    print(root->left);
    cout << root->value << endl;
    print(root->right);
}
