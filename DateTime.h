#ifndef DATETIME_H
#define DATETIME_H
    #ifndef LIBR_H
        #include LIBR_H
    #endif

//-- КОНСТРУКТОР ПО УМОЛЧАНИЮ--
my::DateTime::DateTime():unixTimeFlag(false){;}

//-- КОНСТРУКТОР ПО UNIXTIME--


my::DateTime::DateTime(time_t _unixTime): unixTime(_unixTime){
    unixTimeFlag = false;
    struct tm * timeinfo;
    timeinfo = localtime (& _unixTime);
    year = 1900 + timeinfo->tm_year;
    month = timeinfo->tm_mon;
    day = timeinfo->tm_mday;
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;
}

//-- КОНСТРУКТОР ПО ВРЕМЕНИ--
my::DateTime::DateTime(int _year, int _month, int _day, int h, int m, int s): year(_year), month(_month), day(_day), hour(h), minute(m), second(s){
    unixTimeFlag = false;
}

//-- КОНСТРУКТОР ПО ДАТЕ--
my::DateTime::DateTime(int _year, int _month, int _day): year(_year), month(_month), day(_day), hour(0), minute(0), second(0){
    unixTimeFlag = false;
}


#endif // DATETIME_H
