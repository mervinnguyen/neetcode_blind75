/**
 * @file memCopy.c
 * @brief Implements a simple memory copy function
 * @author Mervin Nguyen
 * @date 2026-05-07
 * @version 1.0.0
 */

 #include <stdio.h>

 /**
 * @brief Copy memory from one location to another.
 *
 * Copies exactly @p n bytes from the memory area pointed to by @p src to
 * the memory area pointed to by @p dest. This implementation copies bytes
 * sequentially and does not provide guarantees for overlapping source and
 * destination regions; use `memmove` for safe overlapping copies.
 *
 * @param src Pointer to the source memory region.
 * @param dest Pointer to the destination memory region.
 * @param n Number of bytes to copy.
 *
 * @note Both @p src and @p dest must be valid for reads and writes of at
 * most @p n bytes respectively. Behavior is undefined if either pointer is
 * NULL or if the regions overlap.
 */
 void mem_copy(void *src, void *dest, size_t n) {
    char *s = (char *)src;
    char *d = (char *)dest;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
 }

 int main(void) {
    char src[8] = "ABCDEFG";
    char dest[8];
    mem_copy(src, dest, sizeof(src));
    printf("Destination after memory copy: %s\n", dest);
    return 0;
 }
