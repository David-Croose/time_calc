/************************************************************************************
                            
                                ti: timer interval 

************************************************************************************/

#include <string.h>
#include "ti.h"

static int32_t is_leap(int16_t year) {
    if (year % 4 == 0 && year % 100) {
        return 1;
    }
    if (year % 400 == 0) {
        return 1;
    }
    return 0;
}

static int32_t check_format(const ti_t *t) {
    if (t->year < 0) {
        return 1; 
    }
    if (t->month < 0 || t->month > 12) {
        return 1;
    }
    if (t->day < 0 || t->day > 31) {
        return 1;
    }
    if (t->hour < 0 || t->hour > 24) {
        return 1;
    }
    if (t->min < 0 || t->min > 60) {
        return 1;
    }
    if (t->sec < 0 || t->sec > 60) {
        return 1;
    }
    return 0; 
}

int32_t ti_calc(const ti_t *t1, const ti_t *t2, ti_t *delta) {
    int8_t montbl[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int8_t days;
    ti_t t;

    if (!t1 || !t2 || !delta) {
        return 1;
    }

    if (check_format(t1) || check_format(t2)) {
        return 4;
    }

    t.year = t2->year - t1->year;
    t.month = t2->month - t1->month;
    t.day = t2->day - t1->day;
    t.hour = t2->hour - t1->hour;
    t.min = t2->min - t1->min;
    t.sec = t2->sec - t1->sec;

    if (is_leap(t2->year)) {
        montbl[1] = 29;
    } else {
        montbl[1] = 28;
    }
    days = montbl[t2->month];
    if (t.sec < 0) {
        t.sec += 60;
        t.min--;
    }
    if (t.min < 0) {
        t.min += 60;
        t.hour--;
    }
    if (t.hour < 0) {
        t.hour += 24;
        t.day--;
    }
    if (t.day < 0) {
        t.day += days;
        t.month--;
    }
    if (t.month < 0) {
        t.month += 12;
        t.year--;
    }

    *delta = t;
    return 0; 
} 

