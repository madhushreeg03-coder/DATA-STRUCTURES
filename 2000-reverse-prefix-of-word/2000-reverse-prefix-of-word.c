#include <string.h>
char* reversePrefix(char* word, char ch) {
    char *end_ptr = strchr(word, ch);
    if (end_ptr == NULL) {
        return word;
    }
    char *start_ptr = word;
    while (start_ptr < end_ptr) {
        char temp = *start_ptr;
        *start_ptr = *end_ptr;
        *end_ptr = temp;
        start_ptr++;
        end_ptr--;
    }
    return word;
}