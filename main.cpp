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
      std::cout<<t.day;
  //    printf ("Current local time and date: %s", asctime(timeinfo));
      return 0;
}
