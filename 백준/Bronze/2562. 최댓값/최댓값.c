#include <stdio.h>
int main()
{
    int i, arr[9], max, m=1;
    
    for(i=0;i<9;i++)
    {
        scanf("%d", &arr[i]);
    }
    max=arr[0];
    for(i=0;i<9;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            m=i+1;
        }
    }
    
    printf("%d\n", max);
    printf("%d", m);
}