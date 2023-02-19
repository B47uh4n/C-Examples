#include<stdio.h>
int main()
{
	
	char kelime[50]; // kullanicidan alacagim kelime icin char olusturdum.
	int boyut=0,i,a=1; // gerekli int degiskenlerimi olusturdum.a degiskenime default olarak 1 degeri verdim.
	
	printf("Lutfen bir kelime giriniz:\n");
	scanf("%s",kelime); // kullanicidan kelimeyi aldim.
	for (boyut=0;kelime[boyut]!='\0';boyut++); // kelimenin boyutunu ölcebilmek icin for dongusu actim ve boyut degiskenimi null karaktere yani kelime sonuna gelene kadar arttirdim.strlen fonksiyonunu kullanip kullanmamakta kararsiz kaldim ve kullanmadan yaptim.
	
	
	for (i=0;i<boyut/2;i++) // kelimenin palindrome olup olmadigini anlamak icin for dongumu actim, kelimenin ilk ve son harfini kiyaslayip ayni hizada ilerlemek icin boyutun yarisindan yararlandim.
    {
    	if (kelime[i]!=kelime[boyut - i - 1]) // her tur bastan ve sondan yaklasacak sekilde if cumlemi kurdum.
		{
    	a=0; // eger bastan ve sondan ayni hizada baktigim harfler esit degilse (kelimem palindrome degilse) a degiskenime 0 degerinin donmesini istedim.
		}
    }
    
    
    if(a==0) // eger a degiskenime 0 degeri donduyse yani kelimem palindrome degilse boyut ile birlikte kullaniciya donus yapmak icin if cumlemi kurdum.
    {
    	printf("%d harften olusan >>%s<< kelimeniz palindrome degildir.",boyut,kelime); 	
	}
    else // eger a degiskenime 0 degeri atanmamissa, yani default degeri olan 1 ise kelimenin palindrome oldugunu boyutu ile kullaniciya yazdirdim.
    {
    	printf("%d harften olusan >>%s<< kelimeniz palindrome'dur.",boyut,kelime);
	}
	//Batuhan DEMIRCI


}
	
