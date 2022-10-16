// https://leetcode.com/problems/swap-nodes-in-pairs/ 

class Solution {
    public void swap (ListNode a , ListNode b) {
        if(a==null || b==null)
            return;
        int temp = a.val;
        a.val = b.val;
        b.val = temp;
    }

    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode odd = head;
        ListNode even = head.next;

        while (even != null && (even.next != null && odd.next != null)) {
            swap(even, odd);
            even = even.next.next;
            odd = odd.next.next;
            
        }
        
        swap(even,odd);
        return head;
    }
}
