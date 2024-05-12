//#include"Date.h"
//
//bool Date::isValidDay(int day) const
//{
//    return (day > 0 && day < 31);
//
//}
//bool Date::isValidMonth(int month) const
//{
//    return (month > 0 && month < 13);
//}
//
//String Date::getMonthStr()
//{
//    String monthList[13]{ "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
//    return monthList[month];
//}
//
//Date::Date()
//{
//    day = 0;
//    month = 0;
//    year = 0;
//}
//
//Date::Date(int refDay, int refMonth, int refYear) :Date()
//{
//    year = (refYear < 0 ? 0 : refYear);
//
//    if (isValidMonth(refMonth))
//    {
//        month = refMonth;
//    }
//
//    if (isValidDay(refDay))
//    {
//        day = refDay;
//    }
//}
//
//void Date::addDays(int inc)
//{
//    if (inc <= 0)
//    {
//        return;
//    }
//    day += inc;
//    while (day>30)
//    {
//        day = day % 30;
//        month++;
//        if (month > 12)
//        {
//            month = month % 12;
//            year++;
//        }
//    }
//}
//
//void Date::subtractDays(int dec)
//{
//    if (dec <= 0)
//    {
//        return;
//    }
//    day -= dec;
//    while (day < 0)
//    {
//        day = day * -1;
//        day = day % 30;
//        month--;
//        if (month < 0)
//        {
//            month = month * -1;
//            month = month % 12;
//            year--;
//        }
//    }
//}
//
//void Date::displayDate()
//{
//    String monthStr = getMonthStr();
//    cout << monthStr << " " << day << ',' << year;
//}
