#ifndef LIBR_H
#define LIBR_H
#ifndef TIME_H
    #include <time.h>
    #define TIME_H
#endif
#ifndef _IOSTREAM
    #include <iostream>
    #define  _IOSTREAM
#endif
#ifndef _NEW
    #include <new>
    #define  _NEW
#endif
#ifndef MATH_H
    #include <math.h>
    #define MATH_H
#endif

namespace my {
class DateTime {
public:
    int year;
    int month;
    int week;
    int day;
    int hour;
    int minute;
    int second;
    bool unixTimeFlag;
    time_t unixTime;
public:
    DateTime();
    DateTime(time_t _unixTime);
    DateTime(int _year, int _month, int _day, int h, int m, int s);
    DateTime(int _year, int _month, int _day);
    //DateTime(string);
};
}


#ifndef DATETIME_H
#include "DateTime.h"
#endif
#endif // LIBR_H
