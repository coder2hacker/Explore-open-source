class Solution {
    List<Integer> l1= new ArrayList<>();
    
    public void reorderList(ListNode head) {
        //  Adding nodes to a list
        ListNode traverse= head;
        
        while(traverse != null){
            l1.add(traverse.val);
            traverse= traverse.next;
        }
        
        if(l1.size() <= 1){
            return;
        }        
        
        traverse= head;
        createList(0, l1.size()-1, traverse);
        return;
    }
    
    public void createList(int left, int right, ListNode traverse){
        if(left > right){
            return;
        }
        
        if(left == right){
            traverse.val= l1.get(left);
            return;
        }
        
        traverse.val= l1.get(left) ;
        traverse.next.val= l1.get(right);
        traverse= traverse.next;
        
        createList(left+1, right-1, traverse.next);
    }
}
