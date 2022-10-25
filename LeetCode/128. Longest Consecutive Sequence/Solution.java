class Solution {
    public int longestConsecutive(int[] nums) {
        int res = 0;// answer len
        Set<Integer> set = new HashSet<>();
        for(int i:nums) set.add(i); // add all elements in a set, we dont require duplicates because - 
        //suppose we have 1 1 2 2 3 3 in the array the max len will be 3 - (1 2 3) doesnt matter how many times a number is present 
        for(int i:nums){
            // the idea is to assume that the present value "i" is the center of the sequence in which it is present 
            // then we will go left and right of it to find the length of its sequence
            // suppose we have 5 1 2 3 4 6 7 8, now the first element we have is 5
            int max = 1,prevVal = i-1,nextVal = i+1; // max is the current length as we have one elemet in the sequence that is 5
            // now for 5 prevVal = 4
            while(set.contains(prevVal)){ // if 4 is present in the set i.e. in the array
                max++; // increase the sequence len
                set.remove(prevVal--); // remove 4 and decremennt prevVal to 3 and continue 
            }
            // removing the elements because an element can only be part of only one consecutive sequence
            while(set.contains(nextVal)){ // same for the nextVal of the sequence
                max++;
                set.remove(nextVal++);
            }
            res = Math.max(res,max); // maintaining max len 
        }
        return res;
    }
}
