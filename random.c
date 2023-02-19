#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    int rastgele[10],toplam=0,ort,max1,max2,i,k;
	
	srand(time(NULL)); 
    for(i=0;i<10;i++)
    {
    	rastgele[i]=rand()%50+25; 
    	printf("%d\n",rastgele[i]);
    }
    
    max1 = rastgele[0];
    max2 = rastgele[1];
 
    if (rastgele[1] > rastgele[0]) 
	{
      max1 = rastgele[1];
      max2 = rastgele[0];
    }
    
    for (k = 2; k < 10; ++k)
	{
	  if (rastgele[k] > max1) 
	  {
         max2 = max1;
         max1 = rastgele[k];
      }
      else if (rastgele[k] > max2)                                                            //rastgele olan sayýmýzýn max1den küçük max2den büyük olma ihtimali
	  {
         max2 = rastgele[k];
      }
	}
    
    for(i=0;i<10;i++)
    {
    	toplam+=rastgele[i];
    	
    }
    ort=toplam/10;
    printf("\ndizinin aritmetik ortalamasi= %d",ort);
 
    printf("\nen buyuk ikinci deger = %d", max2);
   
    if(max1==max2)
    {
   	printf("\t(en buyuk 2 degeriniz birbirine esit)");
    }
    
} //Batuhan Demirci
     
