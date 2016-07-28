#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main (int argc, char *argv[]) {

    char *pattern;
    regex_t regex;              //  Compiled regex.
    char *target;
    int regcomp_status;
    int regexec_status;
    char error_message[8];
    int cflags = 0;
    int eflags = 0;
    const int nmatch = 10;      //  Number of parenthesised subexpressions.
    regmatch_t subex[nmatch];   //  Array of parenthesised subexpressions.

    int i;
    char *tmp;
    int length;

    if (argc == 3) {

        pattern = argv[1];
        target = argv[2];
    }
    else
        return -1;

    /* Compile a regular expression into a data structure that we can use with 'regexec'.   
     * We use function:
     *
     * @ int regcomp(regex_t *restrict compiled, const char *restrict pattern, int cflags)
     *    
     * @ cflags: cflags are bit flags
     *   - REG_EXTENDED: Extended regex.
     *   - REG_ICASE: Ignore case.
     *   - REG_NOSUB: Report only TRUE/FALSE in regexec().
     *   - REG_NEWLINE: Change the handling of newline character.
     *
     **/
    regcomp_status = regcomp(&regex, pattern, cflags);
    printf("Pattern: %s\nTarget: %s\n", pattern, target);

    if (regcomp_status) {
    
        regerror(regcomp_status, &regex, error_message, 8);
        printf("Regex Error Compiling %s : %s\n", pattern, error_message);
        return -1;
    }

    /* Match target string with regex.
     * We use function:
     *
     * @ int regexec(const regex_t *restrict compiled, 
     *               const char *restrict string, 
     *               size_t nmatch, 
     *               regmatch_t matchptr[restrict], 
     *               int eflags)
     *
     * @ eflags: A word of bit flags that enable various options
     *   - REG_NOTBOL: The first character of the string is not BOL(Beggining of line).
     *                 Therefore, the circumflex character (^),
     *                 when taken as a special character, will not match the beginning of string.
     *   - REG_NOTEOL: The last character of the string is not EOL(End of line).
     *                 Therefore, the dollar sign ($),
     *                 when taken as a special character, will not match the end of string
     *
     * @ Return Value
     *   - 0: The pattern matches the string.
     *   - REG_NOMATCH: The pattern didn't match the string. This isn't really an error.
     *   - REG_ESPACE: 'regexec' ran out of memory.
     *
     * If 'nmatch' is 0 or REG_NOSUB flag was set in cflags to regcomp(),
     * then regexec() will ignore the 'matchptr' argument.
     *
     **/
    regexec_status = regexec(&regex, target, nmatch, subex, eflags);

    if (regexec_status) {

        printf("NO MORE MATCHES\n");
        return -1;
    }

    for (i=0; i < nmatch; i++) {
    
        if (subex[i].rm_so == -1 || length < 0)
            continue;

        length = subex[i].rm_eo - subex[i].rm_so;
        tmp = (char *)malloc(sizeof(char) * (length+1));
        tmp[length] = '\0';

        /* strncpy() will not null-terminate if tmp is not large enough. */
        strncpy(tmp, &target[subex[i].rm_so], length);

        printf("$%d: byte %d ~ byte %d, %s", i, subex[i].rm_so, subex[i].rm_eo - 1, tmp);

        if (i == 0)
            printf(" (%s)\n", "Matched Part");
        else
            printf(" (%s \\%d)\n", "Parenthesised Subexpression", i);

        free(tmp);
    }
    
    /* Free the storage the compiled regex uses.
     * We should always free the space in a regex_t structure 
     * before using the structure to compile another regex.
     * We use function:
     *
     * @ void regfree(regex_t *compiled)
     **/
    regfree(&regex);

    return 0;
}
