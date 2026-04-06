/**
 * @file ImplementACircularBuffer.c
 * @brief Circular buffer (ring buffer) implementation for fixed-size integer storage
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef struct circular_buffer{
    int buffer[BUFFER_SIZE];  
    int tail;                
    int head;           
    int count;        
} circular_buffer;

int init_circular_buffer(circular_buffer *cb){
    cb->tail = 0;
    cb->head = 0;
    cb->count = 0;
    return 0;
}

bool is_empty(circular_buffer *cb){
    return (cb->count == 0);
}

bool is_full(circular_buffer *cb){
    return (cb->count == BUFFER_SIZE);
}

int push(circular_buffer *cb, int data){
    if (is_full(cb)){
        return -1;
    }
    cb->buffer[cb->head] = data;
    printf("The value being pushed into buffer is %d\n", cb->buffer[cb->head]);
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count += 1;
    return 0;
}

int pop(circular_buffer *cb, int *data){
    if (is_empty(cb)){
        return -1;
    }
    *data = cb->buffer[cb->tail];
    printf("The value being popped from buffer is %d\n", *data);
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count -= 1;
    return 0;
}

int main(void){
    circular_buffer *cb = malloc(sizeof(circular_buffer));
    int popped_value = 0;
    init_circular_buffer(cb);
    push(cb, 4);
    push(cb, 5);
    push(cb, 6);
    push(cb, 7);
    pop(cb, &popped_value);
    free(cb);
    return 0;
}