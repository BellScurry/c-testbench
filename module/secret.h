typedef struct jongho *jongho_t;

jongho_t init_jongho();
void tell_secret(jongho_t jh, int secret);
int square_secret(jongho_t jh);
