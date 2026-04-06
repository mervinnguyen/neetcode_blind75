/**
 * @file ValidParentheses.cpp
 * @brief Implementation of a bracket validation algorithm using stack data structure
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 * 
 *  Approach:
 * - Use a stack to store opening brackets.
 * - Iterate through the string:
 * - If an opening bracket, push onto the stack.
 * - If a closing bracket, check if it matches the top of the stack.
 * - If not matching or stack is empty, return false.
 * - At the end, the stack should be empty for a valid string.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution{
public: 
    bool isValid(string s){
        stack<char> stack;      
        for (int i = 0; i < s.size(); i++){    
            if (s[i] == '{' || s[i] == '[' || s[i] == '('){
                stack.push(s[i]);  
            }
            if (s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if (stack.empty()){  
                    return false;
                }
                char stack_top = stack.top();  
                if (s[i] == '}' && stack_top != '{' || s[i] == ']' && stack_top != '[' || s[i] == ')' && stack_top != '('){
                    return false;
                } 
                stack.pop();
            }
        }
        return stack.empty();    
    } 
};

int main(){
    Solution sol;
    string s = "{([])}";
    bool result = sol.isValid(s);
    cout << (result ? "true" : "false");
    return 0;
}