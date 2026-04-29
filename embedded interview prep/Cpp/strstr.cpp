/**
 * @file strstr.cpp
 * @brief Given two strings haystack and needle, return the index of the first occurence of needle in haystack, or -1.
 * @author Mervin Nguyen
 * @date 2026-04-29
 * @version 1.0.0
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Returns the index of the first occurrence of @p target in @p source.
 *
 * @param source The string to search within.
 * @param target The string to find.
 * @return The starting index of the first match, or -1 if no match exists.
 */
int str_str(string &source,string &target){
    if (target.empty()){
        return 0;
    }
    if (source.empty() || target.size() > source.size()){
        return -1;
    }
    for (size_t i = 0; i + target.size() <= source.size(); i++){
        size_t j = 0;
        while (j < target.size() && source[i + j] == target[j]){
            j++;
        }
        if (j == target.size()){
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main(){
    string source = "sadbutsad";
    string target = "sad";

    cout << str_str(source, target) << endl;
    
    return 0;
}