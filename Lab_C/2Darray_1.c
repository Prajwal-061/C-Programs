#include <stdio.h>
int main()
{
    int i, j, city, temp, day;
    printf("enter  no of city:");
    scanf("%d", &city);
    printf("enter no. of days:");
    scanf("%d", &day);
    int a[city][day];
    for (i = 0; i < city; i++)
    {
        for (j = 0; j < day; j++)
        {
            printf("enter the temperature for city %d,day %d \n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < city; i++)
    {
        for (j = 0; j < day; j++)
        {
            printf(" city %d,day %d =%d\n", i + 1, j + 1, a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
