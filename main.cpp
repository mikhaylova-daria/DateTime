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
      my::DateTime t(rawtime);  //проверка конструктора от unixTime
      int i;    // ожидание ввода
      std::cin>>i;
      my::DateTime y = my::DateTime::now (); //проверка статического метода и оператора присваивания
      my::TimeSpan dif =y.Dif(t);           //создание промежутка
      std::cout << dif<<'\n';     //вывод промежутка, вывод DateTipe, перевод в строку
      std::cout<<y.str()<<'\n'; //
      my::DateTime p;
      std::cin>>p;
      std::cout<<p<<'\n';
      my::DateTime z = p + dif;
      std::cout<<"Сумма промежутка и только что введённого: "<<z;
//    std::cout<<t.str()<<"\n";
//    std::cout<<y.str()<<"\n";
//    std::cout<<z.str();
//    std::cout<<t.year<<"\n";
//    std::string a = t.str();
////std::cout << y;
//my::DateTime o;
//std:: cin >> o;
//      //my::DateTime x(t.year, t.month, t.day, t.hour, t.minute, t.second);
//  //    t.str();
//     // std::cout<<y.minute;
//      //x.unixT();
////std::cout<<x.day;
//        //std::cout<<x.unixTime<<"\n";
//      // std::cout<<x.hour;
//      //std::cout<<t.day_of_week();
      return 0;
}
