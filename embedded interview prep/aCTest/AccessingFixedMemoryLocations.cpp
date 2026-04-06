/**
 * @file AccessingFixedMemoryLocations.cpp
 * @brief Demonstration of accessing fixed memory locations in embedded systems
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 * 
 * @warning Writing to arbitrary memory addresses can cause system crashes or undefined behavior
 * @note Address 0x67a9 is used as an example and may not be valid on all systems
 */

#include <iostream>

using namespace std;

int main(){
    int *ptr;
    ptr = (int*)0x67a9;
    cout << "The current address of int is: " << ptr << endl;
    *ptr = 0xaa55;
    cout << "The current value at ptr is: " << *ptr << endl;
    return 0;
}