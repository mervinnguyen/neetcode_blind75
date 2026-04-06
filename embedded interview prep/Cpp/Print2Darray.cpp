/**
 * @file Print2Darray.cpp
 * @brief Program to print a 2D array in matrix format
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <iostream>

int main(){
    const int a = 3;    
    const int b = 3;
    int array[a][b] = {{1, 2, 3},      
                        {4, 5, 6},
                        {7, 8, 9}};

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}