#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    printf("address of a is %d\n", p);
    printf("Value at  p is %d\n", *p);
    printf("size of the integers is %d bytes\n", sizeof(int));
    printf("address of p+1 is %d\n", p + 1);  // since here datatype is integers it increments by the value 4.
    printf("value at p+1 is %d\n", *(p + 1)); // it gives the garbage value as no value is stored in that address.
    check();
    check1();
    typecasting();
    new ();
    return 0;
}

// for integer data types
int check()
{
    int a = 1025;
    int *p = &a;
    printf("Address=%d value=%d\n", p, *p); // here value will be 1025 because it is integer datatype
    return 0;
}

// for char datatypes
int check1()
{
    char a = 1025;
    char *p = &a;
    printf("Address=%d value=%d\n", p, *p);           // value will be 1 because of the char datatype.
    printf("Address=%d value=%d\n", p + 1, *(p + 1)); // value will be 1 because of the char datatype.
    return 0;
}

int typecasting()
{
    int a = 65;
    char c;
    printf("integer a=%d", a);
    c = (char)a;
    printf("character a=%c", c);
}

int new()
{
    int a[5] = {1, 5, 7, 0, 3};
    int *p = &a[0];
    printf(" \nvalue is %d\n", *p);
    printf("Address is %u\n", p);
    p = p + 2;
    printf(" value is %d\n", *p);
    printf("address is %u\n", p);
}