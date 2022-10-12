#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node* root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);                    
    if(root->data == key){                          // node found
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){   // TO FIND KEY IN LEFT OR RIGHT SUBTREE
        return true;
    }

    path.pop_back();                                // backtracing
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pc;
    for(pc=0; pc<path1.size() && pc<path2.size(); pc++){
        if(path1[pc] != path2[pc]){                 // path will be same for both the nodes until it reaches to the LCA
            break;
        }
    }
    return path1[pc-1];
}

int LCA2(Node* root, int n1, int n2) {
    if(root == NULL) 
        return -1;
    if(root->data==n1 || root->data==n2)
        return root->data;

    int left = LCA2(root->left, n1, n2);
    int right = LCA2(root->right, n1, n2);

    if(left == -1)  return right;
    if(right == -1)  return left;

    return root->data;
}

/*             1
              / \
             2   3
            / \ / \
           4  5 6  7
          /
         8      
*/

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1=8;
    int n2=5;
    int lca = LCA(root, n1, n2);

    if(lca == -1){
        cout<<"LCA doesn't exist"<<endl;
    }
    else{
        cout<<"LCA : "<<lca<<endl;
    }

    return 0;
}