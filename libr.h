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
#ifndef STRING
    #include <string>
    #define STRING
#endif

namespace my {
class TimeSpan;
class DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    bool unixTimeFlag;
    time_t unixTime;
    int w_day;    // 0, если воскресенье, остальные от 1 до 6
public:
    DateTime();
    DateTime(time_t _unixTime);
    DateTime(int _year, int _month, int _day, int h, int m, int s);
    DateTime(int _year, int _month, int _day);
    int day_of_week();   // 0, если воскресенье, остальные от 1 до 6
    static DateTime now();
    time_t unixT();
    std::string str();
    my::TimeSpan Dif(DateTime);
    DateTime & operator = (DateTime);
    bool operator < (DateTime);
    bool operator > (DateTime);
    bool operator <= (DateTime);
    bool operator >= (DateTime);
    bool operator != (DateTime);
    bool operator == (DateTime);
    DateTime operator + (TimeSpan);
    DateTime operator - (TimeSpan);
    DateTime(std::string);
};
class TimeSpan
{
public:
    DateTime span;
  public:
    friend class DateTime;
};
}
#ifndef DATETIME_H
#include "DateTime.h"
#endif
#endif // LIBR_H
