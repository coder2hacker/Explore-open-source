// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        ListNode head = null;
        ListNode ptr = null;
        PriorityQueue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode>() {
            public int compare(ListNode n1, ListNode n2){
                return n1.val - n2.val;
            }
        });
        for(int i = 0; i < k; i++){
            if(lists[i] != null){
                queue.add(lists[i]);
            }
        }
        while(!queue.isEmpty()){
            ListNode curr = queue.poll();
            if(curr.next != null){
                queue.add(curr.next);
            }
            if(head == null){
                head = curr;
                ptr = head;
            }else{
                ptr.next = curr;
                ptr = ptr.next;
            }
        }
        return head;
    }
}
