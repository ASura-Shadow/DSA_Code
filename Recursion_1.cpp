N to 1 and 1 to N

#include<stdio.h>
void NtoOne(int);
void OnetoN(int);
void main()
{
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    NtoOne(n);
    printf("\n");
    OnetoN(n);
}
void NtoOne(int a)
{
    if(a==0)
    {
        return;
    }
    printf("%d ",a);
    NtoOne(a-1);
}

void OnetoN(int a)
{
    if(a==0)
    {
        return;
    }
    OnetoN(a-1);
    printf("%d ",a);
}


