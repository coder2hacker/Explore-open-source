class Solution {

    Map<Node,Node> map = new HashMap<>();
	
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node temp = new Node(head.val);
        map.put(head,temp);
        temp.next = copyRandomList(head.next);
        temp.random = map.get(head.random);
        return temp;
    }
}
