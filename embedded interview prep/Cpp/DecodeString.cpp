/**
 * @file DecodeString.cpp
 * @brief Given an encoded string in the format "k[encoded_string]", return the decoded string repeated k times.
 * @author Mervin Nguyen
 * @date 2026-05-04
 * @version 1.0.0
 */

 /**
  * @example Examples:
  * - Input: "3[a]2[bc]" → Output: "aaabcbc"
  * - Input: "3[a2[c]]" → Output: "accaccacc"
  */
 #include <iostream>
 #include <string>
 #include <stack>

 using namespace std;

 /**
  * @brief Decodes an encoded string with nested bracket patterns.
  * 
  * Given an encoded string in the format "k[encoded_string]", decodes and returns
  * the string repeated k times. Supports nested patterns like "3[a2[c]]".
  * 
  * @param s The encoded string to decode. Format: digits followed by '[', then
  *          string content, then ']'. Example: "3[a]2[bc]" → "aaabcbc"
  * 
  * @return The decoded string with all patterns expanded and multiplied.
  * 
  * @note Approach:
  *       1) Use a stack to store (previous_string, multiplier) pairs
  *       2) Iterate through each character:
  *          - If digit: build multi-digit numbers
  *          - If '[': push state to stack, reset for nested content
  *          - If ']': pop from stack, multiply string, concatenate
  *          - If letter: append to current string
  *       3) Time Complexity: O(n) | Space Complexity: O(m)
  */
 string decode_string(string s) {
   stack<pair<string, int>> stack;
   string current_string = "";
   int current_num = 0;

   for (char c : s){
      if (isdigit(c)) {
         current_num = current_num * 10 + (c - '0');  /* Build multi-digit numbers*/
      } else if (c == '[') {
         stack.push({current_string, current_num});      /* Push the current state to stack and reset */
         current_string = "";
         current_num = 0;
      } else if (c == ']') {
         auto [prev_string, num] = stack.top(); /*Pop from stack and construct the repeated string */
         stack.pop();
         string temp = "";
         for (int i = 0; i < num; i++){
            temp += current_string;
         }
         current_string = prev_string + temp;
      } else {
         current_string += c;    /*Regular character*/
      }
   }
   return current_string;
 }
 
 int main(void) {
      // Test cases
      cout << decode_string("3[a]2[bc]") << endl;           // "aaabcbc"
      cout << decode_string("3[a2[c]]") << endl;            // "accaccacc"
      cout << decode_string("2[abc]3[cd]ef") << endl;       // "abcabccdcdcdef"
      cout << decode_string("a2[b2[c]]") << endl;           // "abccbcc"

      return 0;
 }