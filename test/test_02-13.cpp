#include <iostream>
using namespace std;
int GetMonthDay(int year, int month)
{
    int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
    {
        return 29;
    }
    else
    {
        return monthArray[month];
    }
}
//int main() {
//    int year = 0, month = 0, day = 0;
//    cin >> year >> month >> day;
//    int count = 0;
//    while (month--)
//    {
//        count += GetMonthDay(year, month);
//    }
//    cout << count << endl;
//}
//int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//int leap(int year) {
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
//    return 0;
//}
//
//int main() {
//    int day1, day2, mon1, mon2, year1, year2;
//    scanf("%4d%2d%2d", &year1, &mon1, &day1);
//    scanf("%4d%2d%2d", &year2, &mon2, &day2);
//    //算出距离0000-00-00的绝对时间，再相减即可
//    int sum1 = 0, sum2 = 0;
//    for (int yy = 0; yy < year1; yy++) {
//        if (leap(yy)) sum1 += 366;
//        else sum1 += 365;
//    }
//    if (leap(year1)) day[2] = 29;
//    else day[2] = 28;
//    for (int mm = 1; mm < mon1; mm++) {
//        sum1 += day[mm];
//    }
//    sum1 += day1;
//
//    for (int yy = 0; yy < year2; yy++) {
//        if (leap(yy)) sum2 += 366;
//        else sum2 += 365;
//    }
//    if (leap(year2)) day[2] = 29;
//    else day[2] = 28;
//    for (int mm = 1; mm < mon2; mm++) {
//        sum2 += day[mm];
//    }
//    sum2 += day2;
//    cout << abs(sum1 - sum2) + 1 << endl;
//    return 0;
//}
int main() {
    int year = 0, count = 0;
    int month = 1;
    int day = 0;
    while (cin >> year >> count) {
        while (count > GetMonthDay(year, month))
        {
            count -= GetMonthDay(year, month);
            ++month;
            if (month > 12)
            {
                ++year;
                month = 1;
            }
        }
        day = count;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

