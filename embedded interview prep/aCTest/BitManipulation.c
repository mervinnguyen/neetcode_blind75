/**
 * @file BitManipulation.c
 * @brief Bit manipulation utilities for setting and clearing a specific bit
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdint.h>

#define BIT_3   (1 << 3)  /**< Bit mask for bit position 3 */

uint32_t set_bit(uint32_t a){
    a |= BIT_3; 
    return a;
}

uint32_t clear_bit(uint32_t a){
    a &= ~BIT_3;    
    return a;
}

int main(void){
    uint32_t reg_val = 0;

    uint32_t set = set_bit(reg_val);
    printf("Current register is: %u \n", set);

    uint32_t clear = clear_bit(reg_val);
    printf("Current register after cleared is: %u", clear);

    return 0;
}