#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int global[2];

//Toplama fonksiyonu
void *toplama_thread(void *arg)
{
    int sayi1,sayi2,top;
    sayi1=global[0];
    sayi2=global[1];
    top = sayi1+sayi2;

    printf("Sayilarin Toplami = %d\n",top);

    return NULL;
}

//cikarma fonksiyonu
void *cikarma_thread(void *arg) 
{
    int sayi1,sayi2,cikar;
    sayi1=global[0];
    sayi2=global[1];
    cikar = sayi1 - sayi2;   

    printf("Sayilarin Farki = %d\n",cikar);

    return NULL;
}

//carpma fonksiyonu
void *carpma_thread(void *arg) 
{
    int sayi1,sayi2,carp;
    sayi1=global[0];
    sayi2=global[1];
    
    carp = sayi1*sayi2;
    
    printf("Sayilarin Carpimi = %d\n",carp);

    return NULL;
}

//bolme fonksiyonu
void *bolme_thread(void *arg) 
{
    int sayi1,sayi2,bol;
    sayi1=global[0];
    sayi2=global[1];
    
    bol = sayi1/sayi2;

    printf("Sayilarin Bolumu = %d\n",bol);

    return NULL;
}

int main() 
{
    printf("1.sayiyi giriniz: ");
    scanf("%d",&global[0]);

    printf("2.sayiyi giriniz: ");
    scanf("%d",&global[1]);
    
    pthread_t tid_top;
    pthread_create(&tid_top,NULL,toplama_thread,global);
    pthread_join(tid_top,NULL);
    
    pthread_t tid_cikar;
    pthread_create(&tid_cikar,NULL,cikarma_thread,global);
    pthread_join(tid_cikar,NULL);
    
    pthread_t tid_carp;
    pthread_create(&tid_carp,NULL,carpma_thread,global);
    pthread_join(tid_carp,NULL);
    
    pthread_t tid_bol;
    pthread_create(&tid_bol,NULL,bolme_thread,global);
    pthread_join(tid_bol,NULL);



    return 0;
}
