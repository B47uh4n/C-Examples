#include<stdio.h>

void tersKopyala(char *g1,char *g2); //fonksiyonumu belirttim.

int boyut;//ozel fonksiyonumda kullanacagim degiskenimi global tanimladim

int main(void)
{
   char *g1,*g2; // 2 adet pointer olusturduk.
   char *kelime1 = "Merhaba, C Programlama ile pointer kullanimlari yapiyoruz."; 
   char kelime2[50];

   for(boyut=0;kelime1[boyut]!='\0';boyut++); //strlen kullanmadan yapmak istedigimiz icin cumlemin boyutunu boyle buldum.
   
   g1=&kelime1[boyut-1]; // pointerýma kelime1 in son karakterinin adresini verdim.
   g2=&kelime2[0]; // g2 icine hicbir deger olmayan kelime2'nin ilk elemaninin adresini koydum.
   
   tersKopyala(g1,g2);	// fonksiyonumu kullandim. 
}

 void tersKopyala( char *g1,char *g2) // fonksiyonumun icerigini yazdim.
{
	int i =0; // gerekli i degerimi belirttim.
	printf("Kelime1'in tersten yazilisi = "); 
	for(i=0;i<boyut;i++) // for dongum ile sondan basa dogru karakterleri yazdirdim.Boylece tersten yazmis oldum.
    {
    printf("%c",*g1);
    --g1;
    }
     
}   //Batuhan Demirci




		
 
