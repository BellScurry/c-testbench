#include <inttypes.h>   /*  <stdint.h> + printf, scanf placeholders, etc.   */
#include <stdio.h>

int main (int argc ,char *argv[]) {

    const int32_t C1 = 0xa1b2c3d4;
    const uint32_t C2 = 0xa1b2c3d4;
    const char *hexstring_without0x = "e5f6";
    const char *hexstring_with0x = "0xe5f6";
    int16_t int16;
    uint16_t uint16;

    /** Test 'printf' Support.  **/
    printf("Print int32_t C1: %" PRIi32 "\n", C1);
    printf("Print int32_t C1 in hex with upper case: %" PRIX32 "\n", C1); 
    printf("Print int32_t C1 in hex with lower case: %" PRIx32 "\n", C1); 
    
    printf("Print uint32_t C2: %" PRIu32 "\n", C2);
    printf("Print uint32_t C2 in hex with upper case: %" PRIX32 "\n", C2); 
    printf("Print uint32_t C2 in hex with lower case: %" PRIx32 "\n", C2); 

    /** Test 'scanf' Support.   **/
    printf("Scan hex string 'e5f6' in int16_t: ");
    sscanf(hexstring_without0x, "%" SCNx16, &int16);
    printf("%" PRIi16 " = 0x%" PRIx16 "\n", int16, int16);

    printf("Scan hex string 'e5f6' in uint16_t: ");
    sscanf(hexstring_without0x, "%" SCNx16, &uint16);
    printf("%" PRIu16 " = 0x%" PRIx16 "\n", uint16, uint16);

    printf("Scan hex string '0xe5f6' in int16_t: ");
    sscanf(hexstring_with0x, "%" SCNx16, &int16);
    printf("%" PRIi16 " = 0x%" PRIx16 "\n", int16, int16);

    printf("Scan hex string '0xe5f6' in uint16_t: ");
    sscanf(hexstring_with0x, "%" SCNx16, &uint16);
    printf("%" PRIu16 " = 0x%" PRIx16 "\n", uint16, uint16);

    return 0;
}
