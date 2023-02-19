#include<stdio.h>

int main()
{

   int fark,i,j,temp; //gerekli int degiskenlerimi verdim.
   int sayilar[8]; //dizimi olusturdum.
   
   for (i=0;i<8;i++) //kullanicidan aldigim veriler ile diziyi olusturmak icin for dongumu actim.
      {
      	printf("%d numarali sayiyi giriniz:\n",i+1);
      	scanf("%d",&sayilar[i]);  // kullanicidan aldigim veriler ile dizimi doldurdum.
      }
      
   for (i=0;i<8;i++) //sayilari buyukten kucuge dizebilmek icin for dongumu actim.
    {
       for(j=7;j>i;j--) //8 elemanli bir dizide buble sort yapmak istedigim icin j=7 verdim boylece ilk turda j'nci(son) elemani diger 7 eleman ile kiyaslayabilecegim, bir sonraki tur i degiskenim 1 artacagi icin yeniledigim j elemanimi diger 6 sayiyla, bir sonraki tur ise yenilenmiþ j elemani diger 5 sayiyla ve boyle giderek her sayiyi birbiriyle kiyaslamis olacagim.  
       	{
       	    if(sayilar[j]>sayilar[j-1])//j.(son) elemanim kendinden bir onceki elemandan buyukse ile onu bir onceki elemanin yerine cekecegim bu islemi for dongusuyle surekli yapacagim boylece en buyuk sayi ilk elemana gelmis olacak.
       	   	{
       	   	    temp=sayilar[j-1]; //j-1'in icine j. elemani koydugumuzda j-1'inci elemani kaybetmemek icin temp degiskenime atadim.
       	   	   	sayilar[j-1]=sayilar[j]; //j-1'inci elemanima j elamanimi atayarak buble sort seklinde buyuk sayiyi bir onceki elemana cekmis oldum.
				sayilar[j]=temp; //temp degiskenime sakladigim j-1'inci elemanimi j. elemanima koydum.
				
			}
       	   	
		}
	}
	
	printf("Sayilariniz buyukten kucuge dogru dizilmistir. ");	
	
	for (i=0;i<8;i++) // sayilari buyukten kucuge sira sira yazdirmak icin for dongumu kullandim.
	{
		printf("\n%3d",sayilar[i]);

    }

    fark=sayilar[0]-sayilar[7]; // max sayi ile min sayi arasindaki farki fark degiskenime atadim.
    printf("\n En buyuk sayi ile en kucuk sayi arasindaki fark %d'dir",fark);
    
    //Batuhan DEMIRCI


}
