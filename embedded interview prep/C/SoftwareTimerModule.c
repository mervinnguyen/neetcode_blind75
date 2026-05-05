/**
 * @file SoftwareTimerModule.c
 * @brief Implement a software timer module in C on top of a single hardware timer. (SysTick or TIM peripheral).
 * @date 2026-04-26
 * @version 1.0.0
 */

 /*
 *  Requirements:
 *   1) Support multiple concurrent software timers (fixed pool, no malloc).
 *   2) Each timer has a callback, a period (in ms), and a one-shot vs. repeating mode.
 *   3) Timers are started/stopped at runtime.
 *   4) The hardware timer ISR drives all software timer expiry.
 */

 #include <stdio.h>

 #define MAX_TIMERS     10.0

 enum timer_state {
    inactive,
    active
 };

 enum mode {
    one-shot,
    periodic
 };

 typedef struct timer {
    int flag;
    mode mode;
    float period_ms;
    float remaining_ms;
    typedef void (*call_back_type)(int);        //define the callback signature using typedef
 } software_timer;

 float array_pool[MAX_TIMERS];

 void SysTick_Handler(void){

 }

 uint32_t ms_to_ticks(float period_ms){
    return (uint32_t)(period_ms * (SYSCLCK_HZ / 1000.0f));
 }

 