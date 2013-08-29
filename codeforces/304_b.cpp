#include <iostream>
#include <stdlib.h>

using namespace std;

int julian(int year, int month, int day) {
  int a = (14 - month) / 12;
  int y = year + 4800 - a;
  int m = month + 12 * a - 3;
  if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15))
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
  else
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
}

int main() {
  int year1, month1, day1;
  int year2, month2, day2;
  int julian_day1, julian_day2;
  int difference;

//  cout << "Enter first date: ";
  cin >> year1;
  if (cin.get() != ':'); /*{ cout << "wrong date input format" << endl; exit(1); }*/
  cin >> month1;
  if (cin.get() != ':'); /*{ cout << "wrong date input format" << endl; exit(1); }*/
  cin >> day1;

 // cout << "Enter second date: ";
  cin >> year2;
  if (cin.get() != ':'); /*{ cout << "wrong date input format" << endl; exit(1); }*/
  cin >> month2;
  if (cin.get() != ':'); /*{ cout << "wrong date input format" << endl; exit(1); }*/
  cin >> day2;

  julian_day1 = julian(year1, month1, day1);
  julian_day2 = julian(year2, month2, day2);

  difference = abs(julian_day2 - julian_day1);
  
  cout << difference << endl;

  return 0;
}


