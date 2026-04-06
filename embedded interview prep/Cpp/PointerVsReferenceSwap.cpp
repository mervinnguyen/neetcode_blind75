/**
 * @file PointerVsReferenceSwap.cpp
 * @brief Demonstrates pointer vs reference parameter passing with swap functions
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>
using namespace std;

/**
 * @brief Swaps the values pointed to by two integer pointers
 * @param[in,out] a Pointer to first integer to swap
 * @param[in,out] b Pointer to second integer to swap
 * @note Uses pointer dereferencing to access and modify values
 */
void swap_ptr(int *a, int *b){
    int i = 0;
    int *temp = &i;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

/**
 * @brief Swaps the values of two integers using reference parameters
 * @param[in,out] c Reference to first integer to swap
 * @param[in,out] d Reference to second integer to swap
 * @note References provide direct access to the original variables
 */
void swap_ref(int &c, int &d){
    int temp = c;
    c = d;
    d = temp;
}

int main(){
    int x, y;
    cout << "Please enter a value for x: ";
    cin >> x;
    cout << "Please enter a value for y: ";
    cin >> y;

    int a = x, b = y;
    swap_ptr(&a, &b);
    cout << "After swap_ptr: a = " << a << " and b = " << b << "\n";

    int c = x, d = y;
    swap_ref(c, d);
    cout << "After swap_ref: c = " << c << " and d =" << d << "\n";

    return 0;
}