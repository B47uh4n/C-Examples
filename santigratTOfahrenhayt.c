#include <stdio.h>

main()
{
	float c,f ;
	printf("Fahrenhayta cevirmek istediginiz santigrat derece degerini giriniz:\n");
	scanf("%f",&c);
	f = (c*1.8) + 32 ;
	printf("%.2f santigrat derece = %.2f fahrenhayt",c,f);
}
