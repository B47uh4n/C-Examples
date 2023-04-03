#include<stdio.h>

void main()
{
    int a[20], i, j, k, n=20; //gerekli degiskenlerimi olusturdum.
    

    srand(time(NULL)); // zamanin surekli degismesinden yararlanarak srand fonksiyonumu kullanip sayilarimin surekli rastgele olmasini sagladim.
    for(i=0;i<20;i++) // 20 tane rastgele sayi uretmek icin for dongusu kullandim.
    {
    	a[i]=rand()%20; //0-20 degerleri arasinda 20 tane rastgele sayi urettim.
    }
   

    printf("\nGercek diziniz: ");
    for(i = 0; i < 20; i++) //kullanicinin ekranina 0-20 arasinda rastgele olusmus ilk dizimizi yazdirmak icin for kullandim.
    {
        printf(" %d", a[i]); //rastgele olusan dizimizin degerlerini sirayla yazdirdim.
    }

    printf("\nYinelenen degerlerin olmadigi diziniz: ");  // kullaniciya yeni dizisini goruntuleyecegimi bildirdim ve dizimizi yinelenen degerlerin olmayacagi sekilde duzenleyip goruntulemek icin assagidaki kodlari kullandim.
    for(i = 0; i < 20; i++) // dongumun 20 kez donmesini saglayan ve dizi elemani kontrolu icin bana kontrol edecegim ilk elemani i degeri ile saglayan for dongumu olusturdum.
    {
        for(j = i+1; j < n; ) // bana kontrol etmem gereken i+1.  (yani j.) degeri saglayan ve j degeri, n icerisinde a dizimin eleman sayisinden baslayarak, sürekli olarak birbiriyle aynı degere sahip 2 elemana denk geldiginde azalan, kısaca dizimizin elemanı azaldığında değişmesi gereken sayidan kucuk oldugu surece devam eden for dongumu olusturdum.
        {
            if(a[j] == a[i]) // eger dizinin i. elemani j. (yani i’den bir sonraki) elemana esit ise 
            {
                for(k = j; k < 20; k++)  // ayni olan 2 degerden 2.sini (yani j. degeri) k degiskenime atadim.Boylece k. degerin icine kendisinden bir sonraki elemani atarak ayni olan 2. degerimizi yok edip dizi elemanlari bitene kadar her elemani bir sola atmami saglayacak olan  for dongumu actim.
                {
                    a[k] = a[k+1]; //k. elemandan baslayarak (yani o andaki j. eleman ) her elemana kendisinden bir sonraki elemani atadim.Yani eger ayni degere sahip 2 eleman bulursam ayni olan 2.  elemandan baslayarak her eleman bir sola kayacak ve ayni olan deger yok olacak.
                }
                n--; // bu islemi yaptiktan sonra dizim bir eleman kaybedecegi icin daha sonra ddizi boyutu olarak kullanacagim n degerini 1 azaltiyorum.
            }
            else
            {
                j++; // eger j. elemanim i.elemanima esit degilse j degerimi arttiriyorum ve i. elemanim ile dizideki diger her elemani kiyaslamis oluyorum.Daha sonra ilk for dongume gidip i degerimi arttiriyorum ve boylece dizideki her eleman (i) daha önce kiyaslanmadigi (i+1 yani j) eleman ile kiyaslanmis oluyor.
            }
        }
    }

    for(i = 0; i < n; i++) // for dongusu kullanarak dizimin duzenlenmis olan butun elemanlarini yazdirmak icin eksilmis olan yeni boyutum (n) kadar elemani yazdiriyorum.
    {
        printf("%d ", a[i]); // yazdirma islemini gerceklestirdim.
    }}
    

