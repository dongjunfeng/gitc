#include <stdio.h>

int main ()
{
    int year = 2018, month = 4, day = 23;
    int sum = 0;
    int leap = 0;
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("leap year ...!\n");
        leap = 1;
    }
    else
    {
        printf("not leap year ...!\n");
    }
    if (month == 1)
    {
        sum = 31 + day;
    }
    else if (month == 2)
    {
        sum = 31 + day;
    }
    else if (month == 3)
    {
        sum = 31 + 28 + leap + day;
    }
    else if (month == 4)
    {
        sum = 31 +28 +leap + 31 +day;
    }
    printf("%d\n",sum);

    return 0;
}
