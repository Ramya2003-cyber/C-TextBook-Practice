#include<stdio.h>
#include <stdlib.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(month<=0||month>12)
    {
        return -1;
    }
    if(day>daytab[leap][month]||day<1)
    {
        return -1;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if((leap&&year>366)||year>365)
    {
        printf("Invalid info");
        exit(0);
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
int main()
{
    int year,month,day;
    printf("Enter year");
    scanf("%d",&year);
    printf("Enter month");
    scanf("%d",&month);
    printf("Enter day");
    scanf("%d",&day);
    int day_count= day_of_year(year,month,day);
    if(day_count==-1)
    {
        printf("Invalid info");
        exit(0);
    }
    else
    {
        printf("The no.of days are %d\n",day_count);
    }
    printf("Enter yearday and year");
    int yearday,year1;
    int m1,d1,*month1,*day1;
    month1=&m1;
    day1=&d1;
    scanf("%d %d",&yearday,&year1);
    month_day(yearday,year1,month1,day1);
    printf("month=%d day=%d",*month1,*day1);

}