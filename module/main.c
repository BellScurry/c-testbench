#include <stdio.h>
#include "secret.h"


int main(int argc, char *argv[])
{
    jongho_t jh;

    jh = init_jongho();
    tell_secret(jh, -3);
    printf("Secret's square: %d\n", square_secret(jh));

    return 0;
}
