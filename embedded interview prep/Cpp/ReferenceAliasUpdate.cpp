/**
 * @file ReferenceAliasUpdate.cpp
 * @brief Demonstrates C++ reference aliasing and indirect value modification
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>
#include <cstdint>
using namespace std;

int main(){
    int32_t a, b; 
    cout << "Please enter a value for A: ";
    cin >> a;
    cout << "Please enter a value for B: ";
    cin >> b;

    int &reference_a = a; 
    int &reference_b = b;

    reference_a += b; 

    cout << "The updated value of a is: " << a;
    return 0;
}