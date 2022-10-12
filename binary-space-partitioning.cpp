// Language: cpp
// Path: Tree/binary-space-partitioning.cpp
// Implementation of the binary space partitioning tree.

#include <bits/stdc++.h>
using namespace std;

// A node of the tree.
struct Node {
    int x, y;
    Node *left, *right;
    Node(int x, int y) : x(x), y(y), left(NULL), right(NULL) {}
};

// A comparator for sorting the points by x-coordinate.
struct XComparator {
    bool operator()(const Node *a, const Node *b) {
        return a->x < b->x;
    }
};

// A comparator for sorting the points by y-coordinate.
struct YComparator {
    bool operator()(const Node *a, const Node *b) {
        return a->y < b->y;
    }
};

// Builds a binary space partitioning tree for the given points.
Node *build(vector<Node *> &points, int depth) {
    if (points.empty()) return NULL;
    if (points.size() == 1) return points[0];
    if (depth % 2 == 0) {
        sort(points.begin(), points.end(), XComparator());
    } else {
        sort(points.begin(), points.end(), YComparator());
    }
    int mid = points.size() / 2;
    Node *node = points[mid];
    vector<Node *> left(points.begin(), points.begin() + mid);
    vector<Node *> right(points.begin() + mid + 1, points.end());
    node->left = build(left, depth + 1);
    node->right = build(right, depth + 1);
    return node;
}

// Prints the tree in the inorder traversal order.
void print(Node *node) {
    if (node == NULL) return;
    print(node->left);
    printf("(%d, %d), ", node->x, node->y);
    print(node->right);
}

int main() {
    vector<Node *> points;
    points.push_back(new Node(2, 3));
    points.push_back(new Node(5, 4));
    points.push_back(new Node(9, 6));
    points.push_back(new Node(4, 7));
    points.push_back(new Node(8, 1));
    points.push_back(new Node(4, 2));
    Node *root = build(points, 0);
    print(root);
    return 0;
}
