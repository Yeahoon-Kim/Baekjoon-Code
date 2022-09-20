#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[101];
    int i, j;

    fgets(arr, 100, stdin);
    for (i = 10; i < 101; i += 10)//10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    {
        for (j = i - 10; j < i; j++)
        {
            if (arr[j] == '\0') exit(0);
            printf("%c", arr[j]);
        }
        printf("\n");
    }
}