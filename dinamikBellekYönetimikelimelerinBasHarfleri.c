#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *kisalt(char *p); // char pointeri donduren ve parametre olarak char pointeri alan fonksiyonumu olusturdum.

int main()
{
	int i,boy; // gerekli int degiskenlerimi tanimladim.
	char cumle [100]; // kullanicidan alacagim cumle icin char degiskenimi olusturdum.
    char *kisa; // fonksiyonumdan dondurecegim pointeri main fonksiyonumda daha iyi kullanabilmek icin icine atayacagim pointeri olusturdum.
    
	while(1) // program kullanici bosluk karakteri girmedigi surece devam etmesi icin while dongumu olusturdum.
	{
	    printf("\nCumlenizi yaziniz:\n"); // kullanicidan cumleyi istedim.
	    gets(cumle); // tek bir kelime degil, bir cumle almak istedigim icin gets komutu ile kullanicidan cumlemi aldim.
	    
        if (cumle[0]==' ') // kullanici bosluk karakteri girdi mi diye kontrol ettim.
	    {
	        return 0; // kullanici bosluk karakteri girdiyse programi sonlandirdim
	    }
	    
        printf("Kelimelerinizin bas harflerinden olusan ifade:"); // ifadeyi acikladim.
        kisa = kisalt(cumle); // fonksiyonumdan dondurdugum pointeri daha rahat kullanabilmek icin kisa adli pointerima aldim.
        
		boy=strlen(kisa); // for dongumde gerektiginden fazla tur atmamak icin kisaltmamin uzunlugunu buldum.
        
        for(i=0;i<boy;i++) // kisaltmamin uzunlugu boyunca karakterleri yazdirabilmek icin for dongusu kullandim.
        {
        	printf("%c",kisa[i]);	// kisaltmamin uzunlugu boyunca harfleri ekrana yazdirdim.
		}
		
        free(kisa); // dinamik bellek yonetimi ile ayirdigim bellegin temizligini yaptim.
        
	
	}
}

char *kisalt(char *p) // fonksiyonumu yazdim.
{
	int i,j=0,bh=1; // gerekli int degiskenlerimi tanimladim.
	int boyut = strlen(p); // parametre olarak verilen char pointerimin isaret ettigi degiskenimin boyutunu aldim.
    
    for(i=0;i<boyut;i++) //parametre olarak aldigim cumlede kac adet bas harf oldugunu bulmak icin for dongusu kullandim.
    {
    	if (p[i]==' ') // bosluk karakteri kontrolu yaptim.
    	{
    		bh++; // cumlenin ilk harfini de sayabilmesi icin 1'den baslattigim bh degiskenim her bosluk karakteri gordugunde 1 artacak.boylece cumledeki toplam bas harf sayisini bulucam.
		}
	}
    
    // bas harfleri bulup geri dondururken gereksiz uzunlukta bir char dizisi kullanmamak icin dinamik bellek yonetiminden yardim aldim .
	char *ptr; // bellek yonetimi ile cumledeki bas harf sayisi uzunlugunda bir hafiza blogu olusturacagim icin olusturdugum blogun adresini atayacagim degiskenimi tanimladim.
	ptr = (char *)calloc(bh,sizeof(char)); // bh sayisi kadar char uzunlugunda hafiza acip adresi ptr pointerima tutturdum.

	
	for (i=0;i<boyut;i++) // her kelimenin bas harfini alabilmek icin for dongumu olusturdum.i degiskenim cumle uzunluguna boyunca her tur 1 artacak.
	{
	    if (i==0) // sadece bir kereye mahsus cumlenin ilk elemanini (eger ilk eleman doluysa) almak icin if kullandim.	
		{
			ptr[0] = p[0];	// parametre olarak aldigim cumledeki ilk bas harfi kendi olusturdugum bh uzunlugundaki hafiza blogumun ilk elemanina aldim.
		}
		
		if(p[i]==' ') // diger kelimelerin bas harflerini alabilmek icin her bosluk elemanindan bir sonraki elemani bulup almam gerek,bu islem icin if kullandim.
		{
			j++; // alicagim bas harfleri hafiza blogumdaki dogru elemanlara koyabilmek icin tanimladigim j degiskenimi her tur 1 arttirdim.
			// boylece bas harflerimi hafiza bloguma gecirirken yukarda ilk [0] elemani yazdirdigim icin once ikinci [1] daha sonra yine birer birer artarak gerektigi yerlere yazilacaklar.
	    	ptr[j]=p[i+1]; // j degiskenimi kullanarak cumlede bosluktan sonraki  elemanlari yani bas harfleri hafiza bloguma aldým.
	    				
		}	
    }
    
    return ptr; // fonksiyonumda olusturup ayarladigim hafiza blogumun adresini dondurdum.

} //Batuhan DEMÝRCÝ
