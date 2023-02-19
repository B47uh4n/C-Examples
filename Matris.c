#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Belirtilen min, max deðerleri arasýnda rasgele deðer atayan fonksiyonu yazacaðýz.
Örneðin min=20, max=90 ise bu matrise 20 ile 90 deðerleri arasýnda rastgele deðer atanacaktýr.
Bu matrisin ilk karþýlaþtýðý 2. maksimum elemanýný bulan ve bulunduðu indisi döndüren bir fonksiyon yazacaðýz.
Bulduðumuz indis satýrýný toplayan bir fonksiyon yazacaðýz. */


void rastgele(int matris[][10],int max,int min); // rastgele matris olusturmak icin fonksiyonumu belirledim.
int *maksimum2(int matris[][10]); // maksimum 2. sayiyi bulabilmek icin fonksiyonumu belirledim.
int topla(int matris[][10],int satir); // maksimum 2. sayinin bulundugu satiri toplamak icin fonksiyonumu belirledim.

int main() 
{	

	int matris [10][10],satir,sutun,max,min,*ptr,indis; // gerekli 10x10 matris, satir sutun, max min gibi ve maksimum 2. sayimin indisini esitleyecegim int degiskenlerimi belirledim, 
	// ayrica en buyuk 2. sayiyi pointer olarak donecegim icin onu main fonksiyonumda daha rahat kullanmak adina esitleyecegim pointeri da olusturdum.
	
	
	printf("Minimum degeri giriniz:"); // kullanicidan olusturulacak rastgele matrisin minumum sayisini istedim.
	scanf("%d",&min);  // min degeri aldim.
	printf("Maximum degeri giriniz:"); // kullanicidan olusturulacak rastgele matrisin minumum sayisini istedim.
	scanf("%d",&max); // max degeri aldim.
	
	rastgele(matris,max,min); // rastgele fonksiyonumu cagirarak max ve min arasinda sayilardan olusan matrisimi olusturdum.
	
	for(satir=0;satir<10;++satir) // rastgele fonksiyonumla olusturdugum matrisi ekrana bastirmak icin for dongumu actim.
	{
		printf("%d- ",satir); // ornekte oldugu gibi her satir dongusu basinda 1 kereye mahsus o satirin kacinci satir oldugunu yazdirdim.
		for(sutun=0;sutun<10;++sutun) // cok boyutlu dizilerimizde genelde yaptigimiz gibi her satirda sutun degerim artarak matrisimi satir satir ilerleyerek yazdirmis olacagim.
		{
			
			printf("%d ",matris[satir][sutun]); // soldan saga ilerleyerek matrisimi yazdirdim
		}
		printf("\n"); // her sutun dongusu bittiginde yani her satirin sonuna geldigimde bir alt satira gecerek matrisi duzenli yazdirdim.
    }
    
    printf("SONUC:\n");
	
	ptr = maksimum2(matris); // maksimum2 fonksiyonumu cagirarak dondurdugu max2 pointerimi daha rahat kullanabilmek icin ptr pointerima atadim.
	printf("en buyuk ikinci eleman : %d " ,*ptr); // bir ust satirda en buyuk 2. elemanin adresini ptr pointerima atamistim, burada * operatoru kullanarak elemanimi bastirdim.
	
	
	for(satir=0;satir<10;++satir) // maksimum2 fonksiyonumdan sadece bir sayi degil pointer dondugum icin sayimin hem adresini hem de kendisini biliyorum boylece adres yardimiyla
	// sayimin hangi indiste bulundugunu yazdirmak icin tekrar matrisimin icinde ilerlememi saglayan for dongumu actim.
	{
		for(sutun=0;sutun<10;++sutun) // yine her satir icin 10 sutun degerim ilerliyor ve boylece butun elemanlari kontrol etmiþ oluyorum.
		{
			if (&matris[satir][sutun]==ptr) // uzerinde ilerledigim matrisimin elemanlarindan adresi ptr adresine esit olan, yani max2 sayimin bulundugu yerde olan elemani kontrol ettim.
			{
		        printf("ve indisi: %d",satir); // max2 sayimin adresinde olduguna gore bu eleman benim max2 sayimin kendisidir.boylece max2 sayimin satirini bulmus oldum ve yazdirdim.
		        indis = satir; // bu satiri daha sonra kullanabilmek icin indis degiskenime atadim boylece ilerde indisteki tum sayilari toplarken kullanabilecegim.
			}	
		}	
    }
	
	printf("\nIndisi %d olan satirin toplami: %d",indis,topla(matris,indis)); // max2 sayimin bulundugu indisteki tum sayilari toplamak icin matrisimi ve,
	// yukarda buldugum indis sayisini topla fonksiyonuma gondererek fonksiyonumun dondurdugu int degeri yazdirdim.

}


void rastgele(int matris[][10],int max,int min) // rastgele matris olusturmak icin fonksiyonumu olusturdum.herhangi bir deger dondurmeden (void) olarak sadece matrisimi olusturdum.
{
	int satir,sutun; // satir ve sutun degiskenlerimi olusturdum.bu degiskenlerime surekli satir sutun veya max min demeyebilirdim ama sorun yaratmayacagi icin daha sade gozukmesini istedim.
	max = max-min; // araligi ayarlarken min degerimi zaten araliga eklemem gerektigi icin max degerimden once cikariyorum boylece assagida max degerime min ekledigimde gercek max'a ulasacagim.
	
	srand(time(NULL)); // surekli rastgele degerler olusturabilmek icin zaman ile surekli degisen time degerimden yararlandým.
	
	for(satir=0;satir<10;++satir) // cok boyutlu dizilerde satir ve sutun elemanlarina bakarken olusturmam gereken for dongumu olusturdum.
	{
		for(sutun=0;sutun<10;++sutun) // her satirda sutun degerim artarak matrisimi doldurmus olacagim yani soldan saga dogru ilerleyecek ve once 1. satir daha sonra 2. satir dolacak.
		{
			matris[satir][sutun]=min+rand()%max; // araligi min degerinden baslatmak icin zaten eklemem gerekti bunu dusunerek yukarda max degiskenimizi duzenledigimiz icin,
			// min degerini eklemis olmam sorun yaratmiyor aksine max degiskenimi olmasi gereken sayiya ulastiriyor.
		}	
    }
}


int *maksimum2(int matris[][10]) // maksimum 2. sayiyi bulabilmek icin fonksiyonumu olusturdum.pointer donmesini istedim boylece sayimin hem kendisini hem de adresini dondurebilecegim.
{
	int *max1,*max2,satir,sutun; // gerekli int pointer ve int degiskenlerimi olusturdum.
    max1 = &matris[0][0]; // max1 pointerima matrisin ilk elemanin adresini atadim.
	max2 = &matris[0][1]; // max1 pointerima matrisin ilk elemanin adresini atadim.
	
	/* maksimum 2. sayiyi bulabilmek icin daha onceki odevlerde de kullandigim algoritmami kullandim, ilk iki sayimin (satir yonunde) hangisinin daha buyuk,
	hangisinin daha kucuk oldugu tespit edip daha sonra bu bilgiye gore matrisimdeki elemanlarin hepsini kontrol edip sonucta en buyuk ve en buyuk 2. degerimi buluyorum     */
	
	if (matris[0][1] > matris[0][0]) // eger yukarda yaptigim degerlendirme yanlissa yani 2. eleman daha buyukse pointer atamalarimi duzeltmek icin kontrol yaptim.
	{   
        max1 = &matris[0][1]; // kontrol sonucuna gore dogru atamalari yaptim.
        max2 = &matris[0][0];
    }
    
	for(satir=0;satir<10;++satir) // butun matris elemanlarimi kontrol edebilmek icin for dongumu actim.
	{
		if (satir==0) // sadece satir 0 iken yani ilk satirda ilk 2 elemani kontrol ettigimden geri kalan kontrollere kaldigi yerden devam etmek kontrolumu yaptim.
		{
			for(sutun=2;sutun<10;++sutun) // sadece ilk satir icin sutun degerimi 2den baslatip surekli arttirarak kontrole devam ettim.
	     	{	
			   if (matris[satir][sutun] > *max1) // eger sutun arttirarak ilerlerken bulundugum eleman max1 degerimizden buyukse o zaman atamalarimi duzelttim.
	           {
                  max2 = max1; // eski max1 degerim daha buyuk bir eleman buldugum icin artik max2 degerim oldu.
                  max1 = &matris[satir][sutun]; // buldugum en buyuk degerim yeni max1 oldu.
               }
            
			   else if (matris[satir][sutun] > *max2)    // kontrol ettigimiz sayimizin max1den küçük max2den büyük olma ihtimaline baktim.
	           {
                  max2 = &matris[satir][sutun]; // bu durumda yeni max2 degerimi atadim.
               }	
	        }
        }
		
		else // diger durumda yani ilk satirda degil isem normal sekilde ilk 2 elemani atlamadan her elemanimi kontrol etmek icin else ile kontrol sagladim.
		{
		   for(sutun=0;sutun<10;++sutun) // satir icin yazdigim for dongumun ilk turundan sonra surekli bu dongum donecek ve her satir icin butun sutunlari kontrol edebilecegim.
		   {
			
			   if (matris[satir][sutun] > *max1) // matrisimde ilerlerken elde ettigim deger max1 degerimden daha buyukse o zaman degiskenlerimi duzenlemek icin kontrol yaptim.
	           {
                  max2 = max1; // eski max1 degerim daha buyuk bir eleman buldugum icin artik max2 degerim oldu.
                  max1 = &matris[satir][sutun]; // buldugum en buyuk degerim yeni max1 oldu.
               }
            
		       else if (matris[satir][sutun] > *max2)    // kontrol ettigimiz sayimizin max1den küçük max2den büyük olma ihtimaline baktim.
	           {
               max2 = &matris[satir][sutun]; // bu durumda yeni max2 degerimi atadim
               }
	       }
	    }
    }
	
	return max2; // fonksiyonda yaptigim islemlerimden sonra elde ettigim max2 pointerimi, yani en buyuk 2. sayimin adresini geri dondurdum	boylece adres ve icerige sahip olabilecegim.	
}


int topla(int matris[][10],int satir) /* max2 sayimin bulundugu satiri toplamak icin fonksiyonumu olusturdum.main fonksiyonumda elde ettigim satir sayisini da parametre olarak
kullandim, bu durumda kolayca sadece sutun degerimi arttirarak butun satirin toplamini bulabilecegim.satir parametremin adini daha sade gozukmesi icin yine satir olarak kullandim.*/
{
    int sut,toplam=0; // gerekli sut ve toplam int degiskenlerimi olusturdum.
	
	for(sut=0;sut<10;++sut) // satir degerimi parametremden kolayca aldigim icin sadece sut degerimi arttirarak ilerlecegim for dongumu actim. 
	{
	    toplam += matris[satir][sut]; // max2 sayimin bulundugunu bildigim satirimdaki sutunlari her tur birbiri ustune gelerek topladim ve toplam degiskenime attim.
	}	
		
    return toplam; // en son butun satirin toplamini geri dondurdum.

}

//Batuhan DEMÝRCÝ







