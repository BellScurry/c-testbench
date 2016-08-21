#include <stdio.h>
#include <stdlib.h>
#include "secret.h"

struct jongho {

    int _init;
    int _secret;
};

struct jongho *init_jongho() {

    struct jongho *jh = (struct jongho *)malloc(sizeof(struct jongho));
    jh->_init = 0;

    return jh;
}

void tell_secret(struct jongho *jh, int secret) {

    jh->_init = 1;
    jh->_secret = secret;
}

int square_secret(struct jongho *jh) {

    if (!jh->_init) {
    
        fprintf(stderr, "struct jongho: NOT INITIALIZED\n");
        return -1;
    }

    return jh->_secret * jh->_secret;
}
