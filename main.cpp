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
      int i;
      std::cin>>i;
      time (&rawtime);
      timeinfo = localtime (&rawtime);
      my::DateTime y(rawtime);
    y = y.Dif(t).span;
    std::cout<<y.str();
      //std::cout<<t.year<<"\n";
/*std::string a = t.str();
std::cout<<a;
      //my::DateTime x(t.year, t.month, t.day, t.hour, t.minute, t.second);
  //    t.str();
      my::DateTime y = t;// my::DateTime::DateTime::DateTime::now();
      std::cout<<(y.month);
     // std::cout<<y.minute;
      //x.unixT();
//std::cout<<x.day;
        //std::cout<<x.unixTime<<"\n";
      // std::cout<<x.hour;
      //std::cout<<t.day_of_week();
  //    printf ("Current local time and date: %s", asctime(timeinfo));*/
      return 0;
}
