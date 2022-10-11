 public ListNode removeNthFromEnd(ListNode head, int n) {

        if(head.next==null){
            return null;
        }
          
        int count =0;
        ListNode node = head;
        while(node!=null){
            count++;
            node = node.next;
        }
        int len = count-n;
         if(len==0){
             return head.next;
         }
       ListNode prev = head;
        int i =1;
        while(i<len){
            prev = prev.next;
            i++;
        }
        prev.next = prev.next.next;
        return head;
    }
