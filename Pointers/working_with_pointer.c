#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    printf("address of a is %x\n", p);
    printf("value at p is %d\n", *p);
    int b = 20;
    *p = b; // will this  address in p change to point b? // NO the address reamains same but value gets modified
    printf("address of a is %x\n", p);
    printf("value at p is %d\n", *p);
    return 0;
}
