#include <stdio.h>


int main (int argc, char *argv[]) {

    int a = 2;

    switch(a) {
        case 0:
            printf("I'm 0\n");
            break;
        case 1:
            printf("I'm 1\n");
            break;
        case 2:
            printf("I'm 2\n");
            //  goto default;   //  Error.
            break;
        default:
            printf("I'm default!\n");
            break;
    }

    return 0;
}
