#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif

int main()
{
    time_t rawtime;
      struct tm * timeinfo;
      time (&rawtime);
      timeinfo = localtime (&rawtime);
      my::DateTime t(rawtime);
      std::cout<<t.unixTime<<"\n";
      my::DateTime x(t.year, t.month, t.day, t.hour, t.minute, t.second);
      //x.unixT();
//std::cout<<x.day;
        //std::cout<<x.unixTime<<"\n";
       std::cout<<x.day_of_week();
      //std::cout<<t.day_of_week();
  //    printf ("Current local time and date: %s", asctime(timeinfo));
      return 0;
}
