#include"Date.hpp"

using namespace std;

Date :: Date() {
  m_year = 0;
  m_month = 0;
  m_day = 0;
  m_hour = 0;
  m_minute = 0;
}

Date :: Date(int year, int month, int day,
  int hour, int minute) {
  m_year = year;
  m_month = month;
  m_day = day;
  m_hour = hour;
  m_minute = minute;
if (!Date :: isValid(*this)) {
    m_year = 0;
  m_month = 0;
  m_day = 0;
  m_hour = 0;
  m_minute = 0;
}

}

Date :: Date(string dateString) {
if (dateString.length() != 16) {
    m_year = m_month = m_day = m_minute = m_hour = 0;
    }
  if (!(dateString[0] - 48 >= 1 && dateString[0] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[1] - 48 >= 0 && dateString[1] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[2] - 48 >= 0 && dateString[2] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[3] - 48 >= 0 && dateString[3] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[5] - 48 >= 0 && dateString[5] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[6] - 48 >= 0 && dateString[6] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[8] - 48 >= 0 && dateString[8] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[9] - 48 >= 0 && dateString[9] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  if (!(dateString[11] - 48 >= 0 && dateString[11] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
    if (!(dateString[12] - 48 >= 0 && dateString[12] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
    }
    if (!(dateString[14] - 48 >= 0 && dateString[14] - 48 <= 9)) {
m_year = m_month = m_day = m_minute = m_hour = 0;
    }
    if (!(dateString[15] - 48 >= 0 && dateString[15] - 48 <= 9)) {
 m_year = m_month = m_day = m_minute = m_hour = 0;
    }
  if (dateString[4] != '-' || dateString[7] != '-' || dateString[10] != '/' || dateString[13] != ':') {
m_year = m_month = m_day = m_minute = m_hour = 0;
  }
  int year;
  int temp[30];
  for (int i = 0; i < dateString.length(); i++) {
    temp[i] = dateString[i] - 48;
  }
  year = temp[0]*1000+temp[1]*100 + temp[2]*10+temp[3];
  int month = temp[5]*10+temp[6];
  int day = temp[8]*10+temp[9];
  int hour = temp[11]*10+temp[12];
  int minute = temp[14]*10+temp[15];
  setYear(year);
  setMonth(month);
  setDay(day);
  setHour(hour);
  setMinute(minute);

}

int Date :: getMonth() const {
  return m_month;
}
int Date :: getYear() const {
  return m_year;
}
int Date :: getDay() const {
  return m_day;
}
int Date :: getHour() const {
  return m_hour;
}
int Date :: getMinute() const {
  return m_minute;
}

void Date :: setYear(const int temp) {
  m_year = temp;
}
void Date :: setMonth(const int temp) {
  m_month = temp;
}
void Date :: setDay(const int temp) {
  m_day = temp;
}
void Date :: setHour(const int temp) {
  m_hour = temp;
}
void Date :: setMinute(const int temp) {
  m_minute = temp;
}

bool isLeap(int year) {
  if (year%4 == 0 && year % 100 != 0 || year % 400 == 0)
    return true;
  return false;
}

int DayinMonth(int month) {
  switch(month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
  return 31;
  case 4:
  case 6:
  case 9:
  case 11:
  return 30;
  default:
  return 28;
}

}
bool Date :: isValid(const Date t_date) {
  bool flag = isLeap(t_date.m_year);
  if (flag) {
//cout << "isleap" << endl;
    if (t_date.m_month == 2 && t_date.m_day > 29) {
//cout << "29\n";
      return false;
} else if (t_date.m_month == 2 && t_date.m_day <= 29)
return true;
  }
  if (!flag) {
    if (t_date.m_month == 2 && t_date.m_day > 28)
      return false;
  }
  if (t_date.m_year < 1000 || t_date.m_year > 9999)
    return false;
  if (t_date.m_month < 1 || t_date.m_month > 12)
    return false;
  if (t_date.m_day < 1 || t_date.m_day > DayinMonth(t_date.m_month))
    return false;
  if (t_date.m_hour < 0 || t_date.m_hour > 23)
    return false;
  if (t_date.m_minute < 0 || t_date.m_minute > 59)
    return false;
  return true;
}

Date Date :: stringToDate(const string dateString) {
  Date tempdate;
  if (dateString.length() != 16) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;}
  if (!(dateString[0] - 48 >= 1 && dateString[0] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[1] - 48 >= 0 && dateString[1] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[2] - 48 >= 0 && dateString[2] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[3] - 48 >= 0 && dateString[3] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[5] - 48 >= 0 && dateString[5] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[6] - 48 >= 0 && dateString[6] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[8] - 48 >= 0 && dateString[8] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[9] - 48 >= 0 && dateString[9] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  if (!(dateString[11] - 48 >= 0 && dateString[11] - 48 <= 9)) {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
    if (!(dateString[12] - 48 >= 0 && dateString[12] - 48 <= 9)) {
      tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
    }
    if (!(dateString[14] - 48 >= 0 && dateString[14] - 48 <= 9)) {
      tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
    }
    if (!(dateString[15] - 48 >= 0 && dateString[15] - 48 <= 9)) {
      tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
    }
  if (dateString[4] != '-' || dateString[7] != '-' || dateString[10] != '/' || dateString[13] != ':') {
    tempdate.m_year = tempdate.m_month = tempdate.m_day = tempdate.m_minute = tempdate.m_hour = 0;
    return tempdate;
  }
  int year;
  int temp[30];
  for (int i = 0; i < dateString.length(); i++) {
    temp[i] = dateString[i] - 48;
  }
  year = temp[0]*1000+temp[1]*100 + temp[2]*10+temp[3];
  int month = temp[5]*10+temp[6];
  int day = temp[8]*10+temp[9];
  int hour = temp[11]*10+temp[12];
  int minute = temp[14]*10+temp[15];
  tempdate.setYear(year);
  tempdate.setMonth(month);
  tempdate.setDay(day);
  tempdate.setHour(hour);
  tempdate.setMinute(minute);
  // if (!Date :: isValid(tempdate)) {
  // tempdate.setYear(0);
  // tempdate.setMonth(0);
  // tempdate.setDay(0);
  // tempdate.setHour(0);
  // tempdate.setMinute(0);
  // }
  return tempdate;
}

string Date :: dateToString(Date date) {
  if (!isValid(date)) {
date.m_year = date.m_month = date.m_day = date.m_hour = date.m_minute = 0;
  }
  char temp[20];
  temp[0] = date.getYear()/1000+48;
  temp[1] = (date.getYear()/100)%10+48;
  temp[2] = (date.getYear()/10)%10+48;
  temp[3] = (date.getYear())%10 + 48;

  temp[4] = '-';

  temp[5] = date.getMonth()/10+48;
  temp[6] = date.getMonth()%10+48;

  temp[7] = '-';

  temp[8] = date.getDay()/10+48;
  temp[9] = date.getDay()%10+48;

  temp[10] = '/';

  temp[11] = date.getHour()/10+48;
  temp[12] = date.getHour()%10+48;

  temp[13] = ':';

  temp[14] = date.getMinute()/10+48;
  temp[15] = date.getMinute()%10+48;

  temp[16] = '\0';

  string tempstring(temp);
  return tempstring;
}

Date& Date :: operator =(const Date& date) {
  m_year = date.m_year;
  m_month = date.m_month;
  m_day = date.m_day;
  m_hour = date.m_hour;
  m_minute = date.m_minute;
  return *this;
}

bool Date :: operator== (const Date& date) const{
if (m_year != date.m_year)
  return false;
if (m_month != date.m_month)
  return false;
if (m_day != date.m_day)
  return false;
if (m_hour != date.m_hour)
  return false;
if (m_minute != date.m_minute)
  return false;
return true;
}

bool Date :: operator>(const Date &date) const {
  if (m_year > date.m_year)
    return true;
  if (m_year < date.m_year)
    return false;
  if (m_month > date.m_month)
    return true;
  if (m_month< date.m_month)
    return false;
  if (m_day> date.m_day)
    return true;
  if (m_day < date.m_day)
    return false;
  if (m_hour > date.m_hour)
    return true;
  if (m_hour < date.m_hour)
    return false;
  if (m_minute > date.m_minute)
    return true;
  if (m_minute < date.m_minute)
    return false;
  return false;
}

bool Date :: operator< (const Date &date) const{
  if (*this > date || *this == date)
    return false;
  return true;
}

bool Date :: operator >=(const Date &date) const {
  if (*this > date || *this == date)
    return true;
  return false;
}

bool Date :: operator <=(const Date &date) const {
  if (*this > date)
    return false;
  return true;
}
