#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
	// Dizinin baslangic adresi icin pointer tanimlamasi
	int* ptr; 
	//Gerekli diger degiskenlerin tanimlanmasi
	int es,temp,i;
	
	printf("Yazdirmak istediginiz eleman sayisini giriniz:\n"); // Kullanicidan yazdirmak istedigi eleman sayisinin alinmasi
	scanf("%d",&es);
	
    ptr =(int *)calloc(es,sizeof(int)); // Dinamik olarak calloc() ile hafizada yer acma
	
	if(ptr==NULL) // Hafizadaki alanin alinip alinamadigi kontrolu. 
	{
		printf("\nHafiza alani alinamadi."); // Alinamadiysa hafiza alinamadi mesaji verilsin
	}             
	else
	{
		printf("\nCalloc ile %d tane tam sayi icin hafizada basarili bir sekilde alan ayrildi.\n",es); //Hafiza basarili bir sekilde ayrildi mesaji
	}

	for (i=0;i<es;i++) // 1'den baslayip girilen sayiya kadar olan sayilari ptr pointeri ile sakla
	{
		*(ptr+i)=i+1;
	}

	printf("\nDizinin elemanlari\n"); // ptr ile sakladigin elemanlari goruntule
	for (i=0;i<es;i++)
	{
	   	printf("%d\n",*(ptr+i));                 
	}	 
		 
	/* Kullanicidan bir onceki girdigi degerden daha buyuk bir sayi girmesini iste eger kullanici daha buyuk bir sayi girmezse kullanici daha buyuk bir sayi girene kadar tekrar tekrar 
	istemeye devam et*/
	while (1)
	{
		printf("\nYazdirmak istediginiz, ilk degerden daha buyuk bir sayi giriniz\n");
		scanf("%d",&temp);
		if(temp>es)
		{
			break;
		}
	}
	
	ptr=realloc(ptr,temp*sizeof(int));	//  Dinamik olarak alinan hafizayi yeniden boyutlandir
		
    printf("\nDizinin tum elemanlari");
	for (i=0;i<temp;i++)	// ptr yardimiyla dizinin elemanlarini yeni hafizaya göre ayarla
	{
		*(ptr+i)=i+1;
		printf("\n%d",*(ptr+i));  // Dizinin tum elemanlarini goruntule
	}	 
		
	free(ptr);	//hafizayi temizle
}
	//Batuhan Demirci
