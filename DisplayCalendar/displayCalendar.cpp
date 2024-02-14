// CSC2034
// 1/31/21

#include <iostream> //cout
#include <string>   //class string
#include <cstdio>   //printf, NULL
using namespace std;

/**
 * @brief Generates a calendar for a future year.
 *
 * @return int
 */
int day_of_week(int y, int m, int d)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    int year;           //the year input by user
    bool isLeapYear;    //true if year is a leap year
    int startDay;       //the 1st day of the month
    int dayCounter;     //incrementer for each day of the year
    string week[7];
    const string DAYS_OF_WEEK[] = { "Sun", "Mon", "Tue",
                                "Wed", "Thu", "Fri", "Sat" };    //name of days of the week
    const string MONTHS[] = { "January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December" };    //name of months
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31 };    //days in each month

    string monthFormat; //temp variable to display month + year

    //Get year for calendar
    cout << "Please enter a year to display:\n" << endl;
    cin >> year;

    //Adjust for leap year.
    // Leap years occur every 4 years, except for hundreds (1900, 2000, etc.)
    if (year % 4 == 0 && year % 100 != 0) {
        isLeapYear = true;
        daysInMonth[1] = 29;
    };

    //get first day of year
    //0 = Sunday, 6 = Saturday
    startDay = day_of_week(year, 1, 1);

    //print calendar for each month of designated year
    for (int curMonth = 0; curMonth < 12; curMonth++) {
        //Build string: [month] [year]
        monthFormat = MONTHS[curMonth] + " " + to_string(year);
        //Print: [month] [year]
        std::printf("%21s\n", monthFormat.c_str());
        std::printf("-----------------------------\n");

        //Iterate over Days
//        std::printf("%d %s\n", __LINE__, "iterate over days header");
        for (string currentDay : DAYS_OF_WEEK) {
            std::printf(" %s", currentDay.c_str());
            // to be completed by student

        }
        std::printf(" \n");

//        std::printf("%d %s\n", __LINE__, "print blank boxes before first day");
        //print empty boxes until start of month
        for (int column = 0; column < startDay; column++) {

            std::printf("    ");
            // to be completed by student

        }

//        std::printf("%d %s\n", __LINE__, "print dates on each row");
        //Print days
        dayCounter = 1;
        while (dayCounter <= daysInMonth[curMonth]) {
            //Print each week row
            for (int column = startDay; column < 7 && dayCounter <= daysInMonth[curMonth]; column++) {
                std::printf(" %2d ", dayCounter);
                // to be completed by student

                dayCounter++;
                startDay++;
            }
            std::printf("\n");
            startDay %= 7;
        }


        std::printf("\n\n");
        startDay %= 7;
    }

    return 0;
}