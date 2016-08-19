#include <stdio.h>
#include <stdarg.h>

/*
 * <stdarg.h> is compatible standard library
 *
 * <stdarg.h> defines
 *   Types: 
 *     va_list
 *   Macro Functions:
 *     va_start
 *     va_arg
 *     va_end
 *     va_copy
 */

int sumNprint (int argc, ...);


int main (int argc, char *argv[]) {

    sumNprint(4, 1, 2, 3, 4);
    sumNprint(5, 5, 6, 7, 8, 9);
    return 0;
}


int sumNprint (int argc, ...) {

    /*
     * Varible Argument List: type 'va_list'
     * The 'va_list' will store arguments in the '...'
     */
    va_list ap;
    va_list ap_copy;
    int i, sum;

    sum = 0;

    /* 
     * Initialization with 'va_start(va_list ap, argN)'
     *
     *   argN: The one just before the '...'
     *        (The rightmost parameter in the variable parameter list)
     */
    va_start(ap, argc);

    /*
     * Copy ap to ap_copy
     * No need to initialize ap_copy with 'va_start'
     */
    va_copy(ap_copy, ap);

    /*
     * Get variable argument value with 'va_arg(va_list ap, type)'
     * The 'va_arg' macro will return NEXT argument
     * in the list pointed to by ap
     *
     */
    for (i=0; i<argc; i++)
        sum += va_arg(ap, int);

    /*
     * Get argument values of ap_copy
     */
    for (i=0; i<argc; i++)
        printf("Entry %d: %d\n", i+1, va_arg(ap_copy, int));

    printf("SUM: %d\n", sum);

    /* Clean up 'va_list' */
    va_end(ap);

    return sum;
}
