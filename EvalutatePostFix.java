 //Input: tokens = ["2","1","+","3","*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9

public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();
        for(String s : tokens){
            if(Objects.equals(s, "+") || Objects.equals(s, "-") || Objects.equals(s, "/") || Objects.equals(s, "*")){

                if(s.equals("+")){
                    int first = Integer.parseInt(stack.pop());
                    int second = Integer.parseInt(stack.pop());
                    int n = second+first;
                    stack.push(Integer.toString(n));
                }

                else if(s.equals("-")){
                    int first = Integer.parseInt(stack.pop());
                    int second = Integer.parseInt(stack.pop());
                    int n = second-first;

                    stack.push(Integer.toString(n));
                }

                else if(s.equals("*")){
                    int first = Integer.parseInt(stack.pop());
                    int second = Integer.parseInt(stack.pop());
                    int n = second*first;

                    stack.push(Integer.toString(n));
                }
                else if(s.equals("/")){
                    int first = Integer.parseInt(stack.pop());
                    int second = Integer.parseInt(stack.pop());
                    int n = second/first;

                    stack.push(Integer.toString(n));
                }
            }
            else{
                stack.push(s);
            }
        }
        return Integer.parseInt(stack.pop());
    }
