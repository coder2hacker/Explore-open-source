package com.company;

import java.util.Stack;

public class QueueUsingTwoStacks {

    static class MyQueue{
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        public boolean isEmpty(){
            return stack1.isEmpty();
        }

        //0(N)
        public void add(int data){
            if (isEmpty()){
                stack1.push(data);
            }
            else {
             while (!isEmpty()){
                 stack2.push(stack1.peek());
                 stack1.pop();
             }
             stack1.push(data);
             while (!stack2.isEmpty()){
                 stack1.push(stack2.peek());
                 stack2.pop();
             }
            }
        }


        //0(1)
        public void remove(){
            if (isEmpty()){
                System.out.println(-1);
            }
            else {
                stack1.pop();
            }
        }

        public int peek(){
            if (isEmpty()){
                return -1;
            }
            return stack1.peek();
        }



    }
    public static void main(String[] args) {
    MyQueue queue = new MyQueue();
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.remove();
    queue.add(4);
    while (!queue.isEmpty()){
        System.out.println(queue.peek());
        queue.remove();
    }

    }
}
