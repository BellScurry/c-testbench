#ifndef _SECRET_H
#define _SECRET_H
typedef struct jongho *jongho_t;

jongho_t init_jongho();
void tell_secret(jongho_t jh, int secret);
int square_secret(jongho_t jh);
#endif
