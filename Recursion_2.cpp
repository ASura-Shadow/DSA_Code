Binary to Decimal and Decimal to Binary
#include<stdio.h>
#include<windows.h>
int dectobin(int);
int bintodec(int,int);
void main()
{
    int n,r,a;
    printf("Enter a number:");
    scanf("%d",&n);
    dectobin(n);
    printf("\n");
    printf("Enter a Binary Number: ");
    scanf("%d",&n);
    a=n;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        if(r>1)
        {
            printf("Invalid Binary Number");
            exit(0);
        }
    }
   r= bintodec(a,1);
   printf("Decimal =%d",r);
}
int dectobin(int m)
{
    int a;
    if(m!=0)
    {
        a=m%2;
        dectobin(m/2);
        printf("%d ",a);
        Sleep(500);
    }
}

int bintodec(int m,int p)
{
    int s=0;
    int r;
    if(m!=0)
    {
        r=m%10;
        s=r*p+bintodec(m/10,p*2);
    }
    return(s);
}
