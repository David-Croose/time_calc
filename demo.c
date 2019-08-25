#include <stdio.h>
#include "ti.h"

int main(void) {
    ti_t t2 = {2019, 3, 12, 15, 26, 46};
    ti_t t1 = {2019, 3, 12, 15, 26, 46};
    ti_t delta;

    if (time_calc(&t1, &t2, &delta) == 0) {
        printf("t2:    %04d-%02d-%02d %02d:%02d:%02d\n", t2.year, t2.month, t2.day, t2.hour, t2.min, t2.sec);
        printf("t1:    %04d-%02d-%02d %02d:%02d:%02d\n", t1.year, t1.month, t1.day, t1.hour, t1.min, t1.sec);
        printf("delta: %04d-%02d-%02d %02d:%02d:%02d\n", delta.year, delta.month, delta.day, delta.hour, delta.min, delta.sec);
    } else {
        printf("error\n");
    } 

    return 0;
}
