#include <stdio.h>
#include <stdlib.h>
int week_day(int year)
{   
  //  Zellers Formula to get week day 
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}
int main()
{   
    int year,month,count=0,daydate=0,day,weekday,daysInMonth=0;
    system("clear");
    printf("Enter The Year:");
    scanf("%d",&year);

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    if((year%4==0&&year%100!=0)||year%400==0)
        {
            monthDay[1]=29;
        }
    daydate=week_day(year);
   for(month=0;month<12;month++)
   {

      daysInMonth=monthDay[month];
      printf("\n\n%s:\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekday=0;weekday<daydate;weekday++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekday>6){
            printf("\n\n");
            weekday=0;
        }
        daydate=weekday;
      } 
    }
}
