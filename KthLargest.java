//Find The kth Largest In The Array
//Using Min Heap

    public int findKthLargest(int[] nums, int k) {
PriorityQueue<Integer> queue = new PriorityQueue<>();
for (int e :nums){
    queue.add(e);
    if (queue.size()>k){
        queue.poll();
    }

}
return queue.peek();
    }
