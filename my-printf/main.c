#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void my_printf(const char *text, ...) {
    va_list args;
    va_start(args, text);

    while (*text) {
        if (*text == '%')
        {
            text++;

            if (*text == 's')
            {

                char *s = va_arg(args, char *);
                write(1, s, strlen(s));

            } else if (*text == 'd' || *text == 'i')
            {

                int i = va_arg(args, int);
                int length = snprintf(NULL, 0, "%d", i);
                char* str = malloc(length + 1);
                int istr = snprintf(str, length + 1, "%d", i);
                write(1, str, istr);
                free(str);

            }
            

            text++;
            
        } else {
            write(1, text, 1);
            text++;
        }
        
    }

    va_end(args);
}

int main() {
    my_printf("Hello world, my name is %s, tenho %d anos!", "Caio", 23);

    return 0;
}