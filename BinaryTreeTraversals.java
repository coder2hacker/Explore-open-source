//preorder traversal
 List<Integer> list = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
           if(root==null){
            return list;
        }
        list.add(root.val);
        preorderTraversal(root.left);
        
        preorderTraversal(root.right);
        
        return list;
    }

//inorder traversal

 List<Integer> list = new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root==null){
            return list;
        }
        inorderTraversal(root.left);
        list.add(root.val);
        inorderTraversal(root.right);
        
        return list;
    }


//postorder traversal

     List<Integer> list = new ArrayList<>();
    public List<Integer> postorderTraversal(TreeNode root) {
         if(root==null){
            return list;
        }
        postorderTraversal(root.left);
      
        postorderTraversal(root.right);
          list.add(root.val);
        return list;
    }
