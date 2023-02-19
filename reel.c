#include<stdio.h>
#include<math.h>

/*Klavyeden iki pozitif tamsayý girilecektir. Girilen bu çiftlerden reel sayýlar oluþturulacaktýr. 
Eðer girilen pozitif tamsayý çifti a ve b ise, reel sayýnýn noktadan önceki tam kýsmýný a ve noktadan sonraki ondalýk kýsmýný b sayýlarýndan oluþturulacaktýr.
Programdaki reel sayý oluþturma iþlemi, çiftlerden birinin negatif olmasýyla sonlanmalýdýr*/

float reel(int a,float b,int hane); // reel sayiya dönüstüren fonksiyonumu tanimladim.
int hanebul (int b); // hane bulma islemi yapan fonksiyonumu tanimladim.

int main()
{
	int hane,a; 
	float b; // gerekli degiskenlerimi tanimladim.
	
	while(1) // negatif sayi girilmedigi surece devam etmesi icin sonsuz dongumu kurdum.
	{
	    printf("Iki sayi giriniz:"); // kullanicidan sayilari istedim.
	    scanf("%d %f",&a,&b); // kullanicidan sayilari aldim.
       
    	if (a<0 || b<0) // negatif sayi girildigi takdirde programi durdurdum.
    	{
    		return 0;
		}
		
		hane = hanebul(b); // hanebul fonksiyonumdan donen degeri hane degerime esitledim.
        printf("Reel sayi:%.5f\n",reel(a,b,hane)); 
		// reel fonksiyonumdan donen a.b halindeki reel sayimi %.5f ile goruntuledim boylece ondalik kisimin kendini 5 haneli gosterecek sekilde esitlemesini sagladim.
		// ornegin 0.782 sayisini ondalik kisimi 5 haneli olacak sekilde gormek istedigimiz icin 0.78200 seklinde esitleyecektir. 
	}   
}


int hanebul (int b) // 0.b seklinde ondalik kismimi olusturabilmek icin ihtiyacim olan b'nin basamak sayisini bulan fonksiyonumu yazdim.
{
	int basamak=0; // basamak degiskenimi belirleyip 0 a esitledim.
	while (b>0) // kalan sayim 0 dan buyuk oldugu surece 10 a bolup basamagi 1 arttirmaya devam etmek icin while dongumu kurdum.
	{
		basamak++; // her turda basamak degiskenimi 1 arttirdim.
		b=b/10; // her turda sayimdan bir basamak eksiltmek icin 10'a boldum.
		
	}
	return basamak; // basamak sayimi dondurdum.
}

float reel(int a,float b,int hane) // reel sayimi olusturan fonksiyonumu yazdim.
{
	float yeni; // sayimin degiskenini tanimladim.
	yeni = a + (b / pow(10,hane)); // girilen b sayimin 0.b haline gelmesi icin b sayimi 10 ussu basamak sayisina boldum. Ornegin 3 haneli b sayisi 10 uzeri 3'e bolunecek ve 0.b haline gelecek.
	// daha sonra tam sayi olacagi icin a sayima hic dokunmadan bu iki sayimi topladim ve a.b olarak yeni reel sayimi elde ettim.
	return yeni; // olusturdugum bu yeni reel sayiyi dondurdum.
	
}

//Batuhan Demirci

