/************************************************************************************

                                ti: timer interval

************************************************************************************/

#ifndef _TI_H_
#define _TI_H_

#include <stdint.h>

typedef struct {
    int16_t year;
    int8_t month;
    int8_t day;
    int8_t hour;
    int8_t min;
    int8_t sec;
} ti_t;

int32_t ti_calc(const ti_t *t1, const ti_t *t2, ti_t *delta);

#endif

