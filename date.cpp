#include "date.h"

Date::Date(){

   
}

Date::Date(const Date& d){
    year = d.year;
    month = d.month;
    day = d.day;

}

int Date::getYear(){

    return year;

 }

int Date::getMonth(){

    return month;

}

int Date::getDay(){

    return day;

}

void Date::setYear(const int& y){
    year = y;

}

void Date::setMonth(const int& m){
    month = m;

}

void Date::setDay(const int& d){

    day = d;

}

bool Date::operator==(const Date& d){
    return year == d.year and
           month == d.month and
           day == d.day;
}
bool Date::operator != (const Date& d){
    return !(*this == d);

    /*return year != d.year and
            month != d.month and
            day != d.day;*/
}

bool Date::operator > (const Date& d){
    return year * 10000 + month * 100 + day >d.year * 10000 + d.month * 100 + d.day;
}

bool Date::operator >= (const Date& d){
    return year * 10000 + month * 100 + day >=d.year * 10000 + d.month * 100 + d.day;
}

bool Date::operator < (const Date& d){
    return year * 10000 + month * 100 + day < d.year * 10000 + d.month * 100 + d.day;
}

bool Date::operator <= (const Date& d){
    return year * 10000 + month * 100 + day <= d.year * 10000 + d.month * 100 + d.day;
}

std::ostream& operator << (std::ostream& os, Date& d){
    os << d.year << "/" << d.month << "/" << d.day;

    return os;
}
std::istream& operator >> (std::istream& , Date& d){

}
