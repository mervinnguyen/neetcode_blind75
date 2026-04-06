/**
 * @file MinStack.cpp
 * @brief Stack supporting push, pop, top, and retrieving the minimum element in O(1) time
 * @author Mervin Nguyen
 * @date 2024-12-19
 * @version 1.0.0
 * 
 * Approach:
 * - Use two stacks: one for all values (main_stack), one for the minimum at each level (min_stack).
 * - On push, add value to main_stack and the new minimum to min_stack.
 * - On pop, remove from both stacks.
 * - top() returns the top of main_stack.
 * - getMin() returns the top of min_stack.
 * 
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    stack<int> main_stack; /**< Stack containing all pushed values */
    stack<int> min_stack;  /**< Stack containing minimum value at each level */

    /**
     * @brief Default constructor for MinStack class
     */
    MinStack() {}
    
    /**
     * @brief Pushes a value onto the stack
     * @param[in] val Value to push onto the stack
     * 
     * @note Maintains the minimum value at each level by pushing the current minimum
     *       (either the new value or the previous minimum) onto min_stack
     */
    void push(int val){
        main_stack.push(val);
        if (min_stack.empty()){
            min_stack.push(val);
        } else {
            int minimum = min(val, min_stack.top());  
            min_stack.push(minimum);   
        }   
    }

    /**
     * @brief Removes the top element from the stack
     * 
     * @note Pops from both stacks to maintain synchronization
     */
    void pop(){
        main_stack.pop();
        min_stack.pop();
    }

    /**
     * @brief Returns the top element of the stack
     * @return The top element value
     */
    int top(){
        return main_stack.top();
    }

    /**
     * @brief Returns the minimum element in the stack
     * @return The minimum element value in O(1) time
     */
    int getMin(){
        return min_stack.top();
    }
};

/**
 * @brief Main function demonstrating MinStack functionality
 * @return Exit status code
 */
int main(){
    MinStack stack; 
    stack.push(1);
    stack.push(2);
    cout << "Current element top of the stack is: " << stack.top() << endl;
    cout << "Current min stack is: " << stack.getMin() << endl;
    stack.pop();
    cout << "Current element top of the stack is: " << stack.top() << endl;
    cout << "Current min element of stack is: " << stack.getMin() << endl;
    return 0;
}