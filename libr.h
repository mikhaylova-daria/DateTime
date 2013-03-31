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
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
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

    friend std::ostream& operator << (std::ostream& ostr, my::DateTime x);
    friend std::istream& operator>> (std::istream&, my::DateTime &);
};
class TimeSpan
{
public:
    DateTime span;
  public:
    friend class DateTime;
    friend std::ostream& operator << (std::ostream& ostr, my::TimeSpan x);
    friend std::istream& operator>> (std::istream&, my::TimeSpan &);
};
std::istream& operator>> (std::istream& istr, my::DateTime & x)
{
    int _year, _month, _day, _hour, _minute, _second;
    istr >> _year;
    istr >> _month;
    istr >> _day;
    istr >> _hour;
    istr >> _minute;
    istr >> _second;
    my::DateTime answer(_year, _month, _day, _hour, _minute, _second);
    x = answer;
    return (istr);
}


std::ostream& operator << (std::ostream& ostr, my::DateTime x)
{
    ostr<<x.str();
    return (ostr);
}

std::istream& operator>> (std::istream& istr, my::TimeSpan & x)
{
    int _year, _month, _day, _hour, _minute, _second;
    istr >> _year;
    istr >> _month;
    istr >> _day;
    istr >> _hour;
    istr >> _minute;
    istr >> _second;
    my::DateTime answer(_year, _month, _day, _hour, _minute, _second);
    x.span = answer;
    return (istr);
}


std::ostream& operator << (std::ostream& ostr, my::TimeSpan x)
{
    ostr<<x.span.str();
    return (ostr);
}
}
#ifndef DATETIME_H
#include "DateTime.h"
#endif
#endif // LIBR_H
