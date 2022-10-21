int diameter_helper(Node* root,int &max_diam){
    if(root == NULL)
    return 0;
    
    int lh = diameter_helper(root->left,max_diam);
    int rh = diameter_helper(root->right,max_diam);
    
    max_diam = max(max_diam,lh+rh+1);
    return max(lh,rh) + 1;  //after updating the max return the height of the current sub tree
}

int diameter(Node* root) {
    // Your code here
    int max_diam = INT_MIN;
    diameter_helper(root,max_diam);  //this function returns the height of the tree
    return max_diam;
}