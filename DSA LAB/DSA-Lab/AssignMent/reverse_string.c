// Write an algorithm to input an array of strings. Then, reverse the string in the format shown below. "ABSTRACT DATA TYPE" should be displayed as "TYPE DATA ABSTRACT"


#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100];
    int i, j, start, end;

    printf("Enter a string: ");
    gets(str);  

    int len = strlen(str);
    printf("%d", len);
    end = len;

    j = 0;
    for(i = len - 1; i >= 0; i--) {
        if(str[i] == ' ' || i == 0) {
            if(i == 0) {
                start = i;
            } else {
                start = i + 1;
            }

            while(start < end) {
                temp[j++] = str[start++];
            }
            temp[j++] = ' '; 

            end = i;
        }
    }

    temp[j-1] = '\0';  

    printf("Reversed string: %s\n", temp);

    return 0;
}

   