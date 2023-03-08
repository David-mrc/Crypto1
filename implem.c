
#include "stdio.h"
#include "mc48.h"

void iterated_tcz48_dm(
    const uint8_t *m, const size_t len, uint8_t h[6]){
if(len%16 != 0){
    fprintf(stderr, "error len not divisible by byte length!\n");
    return;
}

for(int i=0; i<len; i+=16){
    tcz48_dm( (uint8_t) * (m + i * sizeof(uint8_t)), h); 
}

return;
}

void print(const uint8_t *x, const size_t len, const char* s){
    for(int i=0; i<len; i+=2){
        printf("%x", x[i]);
    }
    printf("%s \n", s[1]);
    return;
}

int main(){
    size_t len = 32;
    uint8_t m[len];
    for(int i; i<len; i++){
        m[i] = i;
    }
    uint8_t h[6];
    for(int j=0; j<6 ; j++){
        h[j] = j;
    }

    iterated_tcz48_dm(m, len, h);
    print(h, 6, "");
}