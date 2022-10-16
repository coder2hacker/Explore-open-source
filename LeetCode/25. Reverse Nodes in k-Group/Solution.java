// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head.next == null || k == 1) return head;
		
		// Finding Size
        int size = 1;
        ListNode temp = head;
        while (temp.next != null){
            temp = temp.next;
            size++;
        }
		
        int reverses = size/k; // Number of reversals we have to do 
		
        ListNode prevEnd = head;  // Going to be used for the end of the previously sorted section
        ListNode curr = head;  // Head of the next section we have to sort
        for (int i = 0; i < reverses; i++){
            ListNode a = curr;
            ListNode top = a;
            ListNode b = a.next;
            for (int j = 0; j < k - 1; j++){
                temp = a;
                a = b;
                b = b.next;
                a.next = temp;   
            }
			
            if (i == 0) head = a;
            prevEnd.next = a;
            curr = b;
            prevEnd = top;
			
        }
        prevEnd.next = curr;
        return head;
        
    }
}
