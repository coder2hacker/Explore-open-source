// https://leetcode.com/problems/merge-intervals/

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b)-> Integer.compare(a[0],b[0]));
        Stack<int[]> stack = new Stack();
        stack.add(intervals[0]);    //pushing 1st interval
        
        //2nd interval se compare krenge
        for(int i=1;i<intervals.length;i++){
            
            int startpoint2 = intervals[i][0];  //2nd interval ka start point isliye 2
            int endpoint2 = intervals[i][1];
            
            //first interval stack mai h toh usse pop kro
            int poparray[] = stack.pop();
            
            int startpoint1 = poparray[0];
            int endpoint1 = poparray[1];
            
            //1 3
            //2 6  inko comapre
            int endmax = Math.max(endpoint2,endpoint1);
                
            if(endpoint1 >= startpoint2){
                int [] merge = new int[]{startpoint1,endmax};
                stack.add(merge);      //merge karne ke baad stack mai dal do 
            }else{
                stack.add(poparray);
                 stack. add(intervals[i]);
            }        
        }
        int [][] output = new int [stack.size()][2];
        for(int i=output.length-1;i>=0;i--){
            int []poparray = stack.pop();
            output[i][0] = poparray[0];
            output[i][1] = poparray[1];
        }
        return output;
    }                           
}
