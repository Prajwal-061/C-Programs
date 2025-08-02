#include <stdio.h>
int main()
{
    int a = 5;
    int *p;
    p = &a; // &a= address of a
    printf(" value of a is %d\n", a);
    printf(" value at p is %d\n", *p); // *p points the value that is stored in the address p
    printf(" address of a is %x\n", &a);
    printf(" address of a is %x\n", p);
    printf(" address of pointer p is %x\n", &p);
    *p = 8;
    printf(" value at p after modifying is %d\n", *p);
    printf(" value of a after modifying is %d\n", a);
    printf("Address of a after modifying is %x\n", p);
    printf("Address of pointer after modifying is %x\n", &p);
    return 0;
}
