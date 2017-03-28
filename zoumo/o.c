#include <stdio.h>
#include <math.h>

int main()
{
    int a = 16, b = 44, c = 4;
    int tmp = b*b - 4*a*c;
    printf("tmp = %d\n", tmp);

    float x1, x2;

    if (tmp > 0)
    {
        x1 = (-b + sqrt(tmp))* 1.0 /(2*a);
        x2 = (-b - sqrt(tmp))* 1.0 /(2*a);
        printf("x1 = %f, x2 = %f\n", x1, x2);
    }
    else if (tmp = 0)
    {
        x1 = x2 = -b* 1.0 / (2*a);
    }

    return 0;
}

