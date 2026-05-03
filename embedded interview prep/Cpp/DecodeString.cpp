/*Decode String
    Problem:
    Given an encoded string in the format 'k[encoded_string], return the decoded string repeated k times.

    Example 1:
    Input : s = "3[a]2[bc]"
    Output: "aaabcbc"

    Example 2:
    Input : s = "3[a2[c]]"
    Output : "accaccacc"
*/

#include <iostream>
#include <string.h>

using namespace std;

/* Questions:
    1) For the input string, are we assuming that the string will always be in the format "k[encoded_string]" or should we handle the edge case where it isnt?
    2) Is K always a positive integer, or can it be zero or even negative?
    3) Can the string inside the brackets be empty, like 3[]?

*/

/*
    Approach:
    1) Initialize a stack where the nested brack

*/
string decode_string(string s){

}

int main(){
    auto result = decode_string();
    cout << result << endl;
    return 0;
}

