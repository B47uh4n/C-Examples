#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    int rastgele[100],toplam=0,ort,max1,max2,i,k,min1,min2; //degiskenlerimi tanimladim.
	
	srand(time(NULL)); // zamana bagli time degerimi kullanarak ürettigim sayilarin sürekli degismesini sagladim.
    for(i=0;i<100;i++) // 100 tane sayi uretebilmek icin gerekli for dongumu actim.
    {
    	rastgele[i]=rand()%100;  // 0-100 arasi degerlerimi urettim.
    	printf("%d\n",rastgele[i]); // yarattigim degerleri sirayla ekrana bastirdim.
    }
    
    
    max1 = rastgele[0]; // max1 icine ilk ürettigim sayiyi attim.
    max2 = rastgele[1]; // max2 icine ikinci ürettigim sayiyi attim.
    min1 = rastgele[1]; // min1 icine ilk ürettigim sayiyi attim.
    min2 = rastgele[0]; // min2 icine ikinci ürettigim sayiyi attim.
    // ilk adimda ilk 2 sayidan hangisinin buyuk yada kucuk oldugunu anlayabilmek icin tanimlamalar yaptim.
    
    if (rastgele[1] > rastgele[0]) // eger ilk 2 deger icin yukarida yazdigim tanimlamalar dogru degilse burada kontrol edip duzelttim.
	{
      max1 = rastgele[1]; // gerekli duzeltmeleri yapýp ilk iki sayidan buyuk ve kucuk olanlari max, min degiskenlerimdeki dogru yerlerine atadim.
      max2 = rastgele[0];
      min1 = rastgele [0]; // tek kontrol blogunda hem max hemde min degerlerimi kontrol ettim.
      min2 = rastgele [1];
    }
    
    for (k = 2; k < 100; ++k) // ilk 2 elemandan hangisinin daha buyuk hangisinin daha kucuk oldugunu bildigimiz icin k sayacimi 2'den baslatarak
	                          // dizideki diger tum elemanlari kontrol etmek icin for dongusu kullandim.
	
	{
	  if (rastgele[k] > max1) // eger k. eleman max1 den daha buyukse yani dizide ilerlerken yeni max degerimize ulasma kontrolunu yaptim.
	  {
         max2 = max1;         // eskiden sahip oldugumuz en buyuk degerimiz suan en buyuk 2. degerimizdir.o yuzden max2 icine max1 degerimizi attim.
         max1 = rastgele[k];  // max1 degiskenimize yeni elde ettigimiz en buyuk degeri attim.
      }
      else if (rastgele[k] > max2) // eger karsimiza gelen sayi max1den buyuk degilse fakat max2den buyukse kontrolunu yaptim.                                                           
	  {
         max2 = rastgele[k]; // max2den daha buyuk olan bu degerimizi max2 icine attim.ama max1den kucuk oldugu icin max1i etkilemedi.
      }
	}
    
    for(i=2;i<100;++i)//ayni sekilde ilk elemani kontrol ettigimiz icin i=2 degerimden baslayarak for dongusuyle min degerlerimi arastirmaya basladim.
    {
    	if (rastgele[i] < min1) // eger bulundugum i. deger min1den daha kucuk ise kontrolu yaptým.
    	{
    		min2=min1; // eski min1 degerimi daha kucugunu buldugum icin artik min2 degerime attim.
    		min1=rastgele[i]; // yeni elde ettigim en kucuk elemani min1 degerime atadim.
		}
		else if (rastgele[i] < min2) // eger buldugum i. deger min1den kucuk degil fakat min2den daha kucuk ise diye kontrol ettim.
		{
			min2=rastgele[i]; // yeni min 2 degerimi yerine atadim.
		}		
    }
     
    printf("\nen buyuk deger = %d", max1); // en buyuk degerimi yazdirdim.
    printf("\nen buyuk ikinci deger = %d", max2); // en buyuk 2. degerimi yazdirdim.
    if(max1==max2) // eger rastgele dizimde bulunan en buyuk iki degerim birbirine esitse diye kontrol ettim.
    {
   	printf("\t(Dizinizdeki en buyuk 2 degeriniz birbirine esit)"); // kullaniciya en buyuk iki degerinin  esit oldugunu bildirdim.
    }
   
    printf("\nen kucuk deger = %d", min1);  // en kucuk degerimi yazdirdim.
    printf("\nen kucuk ikinci deger = %d", min2); // en kucuk ikinci degerimi yazdirdim. 
    if(min1==min2) // eger rastgele dizimde bulunan en kucuk iki degerim birbirine esitse diye kontrol ettim.
    {
   	printf("\t(Dizinizdeki en kucuk 2 degeriniz birbirine esit)"); // kullaniciya en kucuk iki degerinin esit oldugunu bildirdim.
    }
	getch();
     
}
     
