#include <stdio.h>
#include "ti.h"

const struct {
    ti_t t1;
    ti_t t2;
} tt[] = {
    {{2019, 6,  12, 9,  26, 16}, {2019, 6,  12, 9,  27, 0}},
    {{2014, 9,  14, 2,  56, 8},  {2014, 11, 18, 2,  56, 19}},
    {{2010, 1,  16, 16, 26, 19}, {2010, 1,  16, 17, 44, 59}},
    {{2001, 12, 21, 6,  26, 2},  {2012, 12, 24, 6,  16, 20}},
    {{1999, 5,  23, 0,  22, 3},  {1999, 7,  23, 0,  8,  9}},
    {{1991, 1,  11, 22, 26, 44}, {1991, 1,  11, 22, 40, 44}},
    {{1977, 10, 8,  6,  26, 2},  {1983, 10, 8,  6,  54, 2}},
    {{1981, 9,  7,  12, 31, 56}, {1981, 9,  7,  8,  34, 56}},
    {{2036, 3,  30, 20, 26, 6},  {2036, 3,  30, 20, 26, 6}},
    {{2073, 11, 29, 2,  26, 9},  {2073, 11, 29, 2,  35, 32}},
    {{1995, 8,  1,  9,  27, 0},  {1995, 8,  3,  12, 44, 0}},
    {{1995, 9,  13, 11, 35, 6},  {1998, 11, 13, 11, 35, 6}},
    {{1912, 6,  25, 6,  26, 27}, {1912, 6,  22, 6,  55, 27}},
    {{1912, 1,  28, 23, 28, 1},  {1912, 1,  28, 15, 20, 2}},
    {{1880, 7,  27, 3,  30, 31}, {1880, 4,  27, 3,  35, 31}},
    {{1831, 9,  24, 10, 2,  43}, {1824, 9,  19, 14, 2,  43}},
    {{1784, 2,  31, 21, 16, 39}, {1784, 2,  31, 21, 16, 39}},
    {{1685, 4,  31, 1,  8,  6},  {1682, 4,  31, 1,  8,  6}},
};

int main(void) {
    ti_t delta;
    ti_t *a, *b;
    int32_t res;
    uint32_t i;

    for (i = 0; i < sizeof(tt) / sizeof(tt[0]); i++) {
        a = (ti_t *)&tt[i].t1;
        b = (ti_t *)&tt[i].t2;

        res = ti_calc(a, b, &delta);
        if (res == 0 || res == 1 || res == -1) {
            printf("t2:    %04d-%02d-%02d %02d:%02d:%02d\n", b->year, b->month, b->day, b->hour, b->min, b->sec);
            printf("t1:    %04d-%02d-%02d %02d:%02d:%02d\n", a->year, a->month, a->day, a->hour, a->min, a->sec);
            printf("delta: %04d-%02d-%02d %02d:%02d:%02d\n", delta.year, delta.month, delta.day, delta.hour, delta.min, delta.sec);
            printf("t2 %s t1\n", (res == 0 ? "==" : (res == 1 ? ">" : "<")));
        } else {
            printf("error, res=0x%08x\n", res);
        }
        printf("\n");
    }

    return 0;
}

