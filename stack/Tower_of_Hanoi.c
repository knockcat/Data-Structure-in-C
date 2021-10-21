/*Tower of Hanoi
 program to solve "Tower of Hanoi" puzzle using number of disks an user input.*/

void TOH(int, char  , char , char);
#include<stdio.h>
int main()
{
        char a = 'A' , b = 'B', c = 'C';

        int n;

        printf("Enter Number of Disk : ");
        scanf("%d",&n);

        TOH(n,a,b,c);

        return 0;      

}

void TOH(int n, char a, char b, char c)
{
    if(n == 1)
    {
        printf("\nMove %c to %c\n",a,b);
    }

    else
    {   
        TOH(n-1,a , c , b);
        printf("\nMove %c to %c \n",a,b);

        TOH(n-1,c, b, a);
        return ;
    }

}