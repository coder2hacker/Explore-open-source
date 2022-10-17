// https://leetcode.com/problems/jump-game-ii/

class MinJumpsTopDownDPSolution{
    static int minJumps(int[] arr){
        // your code here
        int n = arr.length;
        //This map will store values for every index. For every index, it will store, what is the minimum number of jumps
        //required to reach that index
        Map<Integer, Integer> calculatedResultsMap = new HashMap<Integer, Integer>();
        int answer =  minJumpsUtil(arr, n-1, calculatedResultsMap);
        return answer;
    }

    private static int minJumpsUtil(int[] arr, int i, Map<Integer, Integer> calculatedResultsMap) {

        if(i==0) return 0;

        if(calculatedResultsMap.containsKey(i)) {
            return calculatedResultsMap.get(i);
        }

        //To calculate minimum jumps needed for index i, we'll have to go through all j's less than i. For each of them,
        //we'll see if 1) it is possible to jump from j to i. 2) It leads to overall minimum jumps to i. And to do this, first
        //prerequisite is that index j should be reachable.
        int j;
        int minJumpsj;
        int candidateMinJumps;
        int minJumpsSoFar = Integer.MAX_VALUE;
        for(j=i-1; j>=0; j--) {
            //Minimum number of jumps required to reach j
            minJumpsj = minJumpsUtil(arr, j, calculatedResultsMap);
            //If j is reachable
            if(minJumpsj != - 1) {
                //If it is possible to directly jump from j to i
                if(arr[j] >= i-j) {
                    //One possible way to reach i is through j. And minjumps to i coming via j will be this.
                    candidateMinJumps = minJumpsj + 1;
                    //If this candidate answer is lesser than what was the minimum so far, then this is our new minimum.
                    if(candidateMinJumps < minJumpsSoFar) {
                        minJumpsSoFar = candidateMinJumps;
                    }
                }
            }
        }

        //If there was no possibility of jumping to i using any of these j, that means i is unreachable.
        if(minJumpsSoFar == Integer.MAX_VALUE) {
            minJumpsSoFar = -1;
        }

        //Put the answer in map before returning the result.
        calculatedResultsMap.put(i, minJumpsSoFar);
        return minJumpsSoFar;
    }
}
