#include <stddef.h>  // for size_t
void *memcpy(void *dest, const void *src, unsigned long n) {
    char *d = dest;
    const char *s = src;
    while (n--) *d++ = *s++;
    return dest;
}

void *memset(void *s, int c, unsigned long n) {
    char *p = s;
    while (n--) *p++ = c;
    return s;
}
