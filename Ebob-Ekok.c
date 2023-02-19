#include<stdio.h>

int main ()
{
	int sayi1, sayi2, i;
    printf ("Ilk sayiyi giriniz: ");
    scanf  ("%d", &sayi1);
    printf("Ikinci sayiyi giriniz:");
    scanf("%d",&sayi2);
    
    for (i=1;i<=sayi1*sayi2;i++)
    {
        if (i%sayi1==0 && i%sayi2==0)
        {
            printf (" EKOK(%d,%d) : %d\n", sayi1,sayi2,i);
            break;
		}
    }
       
    if(sayi1>sayi2)
	{
	    i=sayi1;
	}
	else
	{
		i=sayi2;
	}

    for (; i > 0; i --)
    {
        if (sayi1 % i == 0 && sayi2 % i == 0) 
        { 
        printf (" EBOB(%d,%d) : %d\n",sayi1,sayi2, i);             
            break;
        }
    }
    getch();

} //Batuhan Demirci
