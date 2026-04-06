/**
 * @brief Incorrect example of interrupt service routine implementation
 * @warning This function demonstrates multiple ISR violations:
 *          - ISRs cannot return a value (void only)
 *          - ISRs should not take parameters
 *          - Floating point operations are not safe or re-entrant in ISRs
 *          - ISRs should be short and avoid complex operations like printf
 * @param[in] radius Radius value (INVALID - ISRs cannot have parameters)
 * @return area Calculated area (INVALID - ISRs must return void)
 * @note This code serves as an educational example of what NOT to do in an ISR
 */

__interrupt double compute_area(double radius){
    double area = PI * radius * radius;
    printf("\nArea = %f", area);
    return area;
}