// Language: cpp
// Path: Tree/suffix-tree.cpp
// Implementing Suffix Tree
#include <bits/stdc++.h>
using namespace std;

struct node {
    int start, end;
    map<char, node*> children;
    node(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct suffix_tree {
    string s;
    node* root;
    suffix_tree(string s) {
        this->s = s;
        root = new node(-1, -1);
        for (int i = 0; i < s.size(); i++) {
            insert(i);
        }
    }
    void insert(int i) {
        node* cur = root;
        while (i < s.size()) {
            if (cur->children.find(s[i]) == cur->children.end()) {
                cur->children[s[i]] = new node(i, s.size() - 1);
                return;
            }
            node* next = cur->children[s[i]];
            int j = next->start;
            while (j <= next->end && s[j] == s[i]) {
                i++;
                j++;
            }
            if (j > next->end) {
                cur = next;
            } else {
                node* split = new node(next->start, j - 1);
                split->children[s[j]] = next;
                next->start = j;
                cur->children[s[i]] = split;
                return;
            }
        }
    }
    void print(node* cur, int depth) {
        for (int i = 0; i < depth; i++) {
            cout << " ";
        }
        if (cur->start == -1) {
            cout << "root";
        } else {
            for (int i = cur->start; i <= cur->end; i++) {
                cout << s[i];
            }
        }
        cout << endl;
        for (auto it : cur->children) {
            print(it.second, depth + 1);
        }
    }
};

int main() {
    string s;
    cin >> s;
    suffix_tree st(s);
    st.print(st.root, 0);
}
