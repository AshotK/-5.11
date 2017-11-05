#include <iostream>
#include <cstdlib>

using namespace std;

class Date{
public:
    Date(unsigned short year, unsigned char month, unsigned char day) : year_(year), month_(month), day_(day){}

    Date(const Date & date) : year_(date.year_), month_(date.month_), day_(date.day_){}

    Date & operator=(const Date & date){
        if (this != &date){
            year_=date.year_;
            month_=date.month_;
            day_=date.day_;
        }
        return *this;
    }

    bool operator<(const Date & other) const {
        if (year_<other.year_) return true;
        if (year_==other.month_) {
            if (month_<other.month_) return true;
            return month_==other.month_ && day_ < other.day_;
        }
        return false;
    }


    unsigned short day0fWeek(){
        return ((day_ + 13*(month_ +1)/5 + year_ + year_/400 + year_/4 - year_/100)%7 + 5)%7 + 1;
    }

    unsigned char day(){
        return day_;
    }

    unsigned char month(){
        return month_;
    }

    unsigned short year(){
        return year_;
    }

private:
    unsigned short year_;
    unsigned char month_;
    unsigned char day_;
};

void swapDates(Date & firstDate, Date & secondDate){
    Date temp = secondDate;
    secondDate = firstDate;
    firstDate =temp;
}

bool isLeap(unsigned short year){
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

unsigned char daysInMonth(unsigned char month, unsigned short year){
    switch (month){
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

unsigned short yearsBetweenTwoDates(Date firstDate, Date secondDate){
    if (secondDate < firstDate) swapDates(firstDate, secondDate);
    unsigned short temp = secondDate.year() - firstDate.year() - 1;
    if (secondDate.month() > firstDate.month() || secondDate.month() == firstDate.month() && secondDate.day() >= firstDate.day()){
        ++temp;
    }
    return temp;
}

unsigned short monthBetweenTwoDates(Date firstDate, Date secondDate){
    if (secondDate < firstDate) swapDates(firstDate, secondDate);
    unsigned short temp = yearsBetweenTwoDates(firstDate, secondDate) * 12;
    temp += (secondDate.month() - firstDate.month());
    if (secondDate.month() < firstDate.month()) temp += 12;
    if (secondDate.day() < firstDate.day()) --temp;
    return temp;
}

unsigned int countDaysInYear(unsigned short year){
    unsigned int temp = 0;
    for (unsigned char month = 1; month < 13; ++month){
        temp += daysInMonth(month, year);
    }
    return temp;
}

unsigned int count(Date & date){
    unsigned int temp = 0;
    for (unsigned short i = 1; i < date.year(); ++i){
        temp += countDaysInYear(i);
    }
    for (unsigned char i = 1; i < date.month(); i++){
        temp += daysInMonth(i, date.year());
    }
    return temp + date.day();
}

unsigned int daysBetweenTwoDays(Date firstDate, Date secondDate) {
    if (secondDate < firstDate){
        swapDates(firstDate, secondDate);
    }
    return count(secondDate) - count(firstDate);
}

int main() {
    Date date(2017, 11, 5), date2(2017, 11,25);
    cout << "days:" << daysBetweenTwoDays(date2, date) << endl;
    cout << "month:" << monthBetweenTwoDates(date2, date) << endl;
    cout << "years:" << yearsBetweenTwoDates(date, date2) << endl;

    Date date3(2014, 12, 5), date4(2016, 10, 5);
    cout << "days:" << daysBetweenTwoDays(date4, date3) << endl;
    cout << "month:" << monthBetweenTwoDates(date4, date3) << endl;
    cout << "years:" << yearsBetweenTwoDates(date3, date4) << endl;
    return 0;
}
