/**
 * @file ReferenceParameterUpdate.cpp
 * @brief Program demonstrating reference parameter passing to update integer values
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>
#include <cstdint>
using namespace std;

void update(int32_t &x, int32_t delta){
    x += delta;
}

int main(){
    int32_t x = 0, delta = 0;
    cin >> x >> delta;

    update(x, delta);

    cout << x;
    return 0;
}