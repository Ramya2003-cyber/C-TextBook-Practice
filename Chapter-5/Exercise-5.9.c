#include <stdio.h>
#include <stdlib.h>
static char months_no_leap[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char months_with_leap[]= {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2]={months_no_leap,months_with_leap};
int day_of_year(int year, int month, int day)
{
    int  leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
   
    if (month <= 0 || month > 12)
    {
        return -1;
    }
    if (day >*(daytab[leap]+month)|| day < 1)
    {
        return -1;
    }
    for (int i=1; i<month;i++)
        day += *(daytab[leap]+i);
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int yearday, int year, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if ((leap && yearday > 366) || yearday > 365)
    {
        printf("Invalid info");
        exit(0);
    }
    for (i = 1; yearday > *(daytab[leap]+i); i++)
    {
        yearday -= *(daytab[leap] + i);
       // printf("%d\n",*(daytab[leap]+i));
    }
        
    *pmonth = i;
    *pday = yearday;
}
int main()
{
    int year, month, day;
    printf("Enter year");
    scanf("%d", &year);
    printf("Enter month");
    scanf("%d", &month);

   printf("Enter day");
   scanf("%d", &day);
    int day_count = day_of_year(year, month, day);
    if (day_count == -1)
    {
        printf("Invalid info");
        exit(0);
    }
    else
    {
        printf("The no.of days are %d\n", day_count);
    }
    printf("Enter yearday and year");
    int yearday, year1;
    int m1, d1, *month1, *day1;
    month1 = &m1;
    day1 = &d1;
    scanf("%d %d", &yearday, &year1);
    month_day(yearday, year1, month1, day1);
    printf("month=%d day=%d", *month1, *day1);
}