#ifndef DATETIME_H
#define DATETIME_H
    #ifndef LIBR_H
        #include LIBR_H
    #endif

//-- КОНСТРУКТОР ПО УМОЛЧАНИЮ--
my::DateTime::DateTime():unixTimeFlag(false){;}

//-- КОНСТРУКТОР ПО UNIXTIME--


my::DateTime::DateTime(time_t _unixTime): unixTime(_unixTime){
    unixTimeFlag = true;
    struct tm * timeinfo;
    timeinfo = localtime (& _unixTime);
    year = 1900 + timeinfo->tm_year;
    month = 1 + timeinfo->tm_mon; //номер месяца
    day = timeinfo->tm_mday;
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;
    w_day = timeinfo->tm_wday;
}

//-- КОНСТРУКТОР ПО ВРЕМЕНИ--

my::DateTime::DateTime(int _year, int _month, int _day, int h, int m, int s): year(_year), month(_month), day(_day), hour(h), minute(m), second(s){
    unixTimeFlag = false;
}

//-- КОНСТРУКТОР ПО ДАТЕ--

my::DateTime::DateTime(int _year, int _month, int _day): year(_year), month(_month), day(_day), hour(0), minute(0), second(0){
    unixTimeFlag = false;
}

//  СТАТИЧЕСКИЙ МЕТОД, ВОЗВРАЩАЮЩИЙ ТЕКУЩЕЕ ВРЕМЯ

my::DateTime my::DateTime::now()
{
      time_t rawtime;
      struct tm * timeinfo;
      time (&rawtime);
      timeinfo = localtime (&rawtime);
      my::DateTime t(rawtime);
      return t;
}

//время в формате unixtime

time_t my::DateTime::unixT(){
    if (unixTimeFlag){
        return unixTime;
    } else {
        unixTimeFlag = true;
        int day_month;
        switch (month)
        {
            case 1: day_month = day - 1; //целые дни!
                break;
            case 2: day_month = day - 1 + 31;
                break;
            case 3:
                if (year % 4 ==  0 )//год високосный
                {
                    day_month = day - 1 + 31 + 29;
                } else {
                    day_month = day - 1 + 31 + 28;
                }
                break;
            case 4:
                 if (year % 4 ==  0 )//год високосный
                 {
                    day_month = day - 1 + 31 * 2 + 29;
                 } else {
                    day_month = day - 1 + 31 * 2 + 28;
                 }
                break;
            case 5:
                if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                    day_month = day - 1 + 31 * 2 + 29 + 30;
                 } else {
                     day_month = day - 1 + 31 * 2 + 28 + 30;
                 }
                break;
            case 6:
                  if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                  {
                       day_month = day - 1 + 31 * 3 + 29 + 30;
                  } else {
                      day_month = day - 1 + 31 * 3 + 28 + 30;
                  }
                break;
            case 7:
                 if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                        day_month = day - 1 + 31 * 3 + 29 + 30 * 2;
                  } else {
                        day_month = day - 1 + 31 * 3 + 28 + 30 * 2;
                  }
                break;
            case 8:
             if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                     day_month = day - 1 + 31 * 4 + 29 + 30 * 2;
                 } else {
                     day_month = day - 1 + 31 * 4 + 28 + 30 * 2;
                }
                break;
            case 9:
              if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                       day_month = day - 1 + 31 * 5 + 29 + 30 * 2;
                  } else {
                       day_month = day - 1 + 31 * 5 + 28 + 30 * 2;
                  }
                break;
            case 10:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                   day_month = day - 1 + 31 * 5 + 29 + 30 * 3;
                } else {
                   day_month = day - 1 + 31 * 5 + 28 + 30 * 3;
                }
                break;
            case 11:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                    day_month = day - 1 + 31 * 6 + 29 + 30 * 3;
                } else {
                     day_month = day - 1 + 31 * 6 + 28 + 30 * 3;
                }
                break;
            case 12:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                      day_month = day - 1 + 31 * 6 + 29 + 30 * 4;
                 } else {
                         day_month = day - 1 + 31 * 6 + 28 + 30 * 4;
                 }
                 break;

        }
        int year_366 = (year - 1970) / 4 - (year - 1970) / 100 + (year - 1970) / 400; //количество високосных лет (c 1972) ( 2000 вычеркнули)
        int year_365 = year - 1970 - year_366; //количество невисокосных лет
        unixTime = (year_366 * 366 + year_365 * 365 + day_month) * 86400  + 3600 * hour + 60 * minute + second + 72000; //без этих двух часов не сходится((( мб часовой пояс?
        struct tm * timeinfo;
         timeinfo = localtime (& unixTime);
         w_day = timeinfo->tm_wday;
         return unixTime;
    }

}

//1 Январь	31
//2	Февраль	28 (в високосном году — 29)
//3	Март	31
//4	Апрель	30
//5	Май	31
//6	Июнь	30
//7	Июль	31
//8	Август	31
//9	Сентябрь	30
//10	Октябрь	31
//11	Ноябрь	30
//12	Декабрь	31

//    1 минута	60 секунд
//    1 час	3600 секунд
//    1 день	86400 секунд
//    1 неделя	604800 секунд
//    1 месяц (30.44 дней) 	2629743 секунд
//    1 год (365.24 дней) 	 31556926 секунд



// ДЕНЬ НЕДЕЛИ

int my::DateTime::day_of_week()
{
    if (unixTimeFlag) {
        return w_day;
    } else {
        unixTime = unixT();
        std::cout<<unixTime<<"\n";
        return w_day;
    }
}

#endif // DATETIME_H
