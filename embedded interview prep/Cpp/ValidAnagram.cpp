/**
 * @file ValidAnagram.cpp
 * @brief Implementation of anagram validation using string sorting approach
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t){
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return (s == t);
        }
};

int main(){
    Solution sol;
    string s = "EmbeddedSystems";
    string t = "SystemsEmbedded";
    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl;
    return 0;
}