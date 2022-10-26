class LRUCache {
    ListNode head;
    ListNode tail;
    HashMap<Integer, Integer> valueMap;
    HashMap<Integer, ListNode> nodeMap;
    int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        valueMap = new HashMap<>();
        nodeMap = new HashMap<>();
        head = new ListNode();
        tail = new ListNode();
        head.next = tail;
        head.prev = null;
        tail.prev = head;
        tail.next = null;
    }
    
    public int get(int key) {
        if(valueMap.containsKey(key)){
            int value = valueMap.get(key);
            update(key);
            return value;
        }
        return -1;
    }
    public void remove() {
        ListNode node = tail.prev;
        ListNode prev = node.prev;
        prev.next = tail;
        tail.prev = prev;
        node.next = null;
        node.prev = null;

        int val = node.val;
        nodeMap.remove(val);
        valueMap.remove(val);
    }
    public void put(int key, int value) {
        valueMap.put(key, value);
        update(key);
        if(nodeMap.size() > capacity){
            remove();
        }
    }
    public void update(int key){
        // Never have it
        ListNode node;
        if(!nodeMap.containsKey(key)){
            node = new ListNode(key);
            moveToHead(node);
            nodeMap.put(key, node);
        }else{ //Already have it
            node = nodeMap.get(key);
            if(head.next != node){ //Not at head
                ListNode next = node.next;
                ListNode prev = node.prev;
                next.prev = prev;
                prev.next = next;
                moveToHead(node);
            }
        }
    }
    public void moveToHead(ListNode node){
        ListNode next = head.next;
        node.next = next;
        next.prev = node;
        head.next = node;
        node.prev = head;
    }
}
class ListNode {
    ListNode next;
    ListNode prev;
    int val;
    public ListNode() {
    }
    public ListNode(int key) {
        this.val = key;
    }
}
