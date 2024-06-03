#include <iostream>
#include <time.h>




int main()
{
	int sayilar[500]{};
	int sayilar2[500]{};
	int  gecici,sayi = 0;
	srand(time(NULL));
	for (int i = 0;i < 500;i++) {
		sayi = rand() % 1000 + 1;
		sayilar[i] = sayi;
		sayilar2[i]=sayi;
	}
	for (int i = 0;i < 500;i++) {
		printf("%d ",sayilar[i]);
	} 
	clock_t baslangic, bitis;
	double gecen_sure;

	printf("------------------------------------------------------------\n"); //selectionsort
	baslangic = clock();
	for (int i = 0;i < 499;i++) {
		for (int j = i + 1;j < 500;j++) {
			if (sayilar[j] < sayilar[i]) {
				gecici = sayilar[i];
				sayilar[i] = sayilar[j];
				sayilar[j] = gecici;
			}
		}
	}

	for (int i = 0;i < 500;i++) {
		printf("Selection Sort ile siralanmis dizi elemanlari = %d \n", sayilar[i]);
	}
	bitis = clock();
	gecen_sure = ((double)(bitis - baslangic));
	printf("Selection sort islemi %.2f saniye surdu.\n", gecen_sure);


	printf("------------------------------------------------------------\n");//Insertion Sort
	baslangic = clock();

	for (int i = 0;i < 500;i++) {
		gecici = sayilar2[i];
		int j = i - 1;
		while (j > -1 && sayilar2[j] > gecici) {
			sayilar2[j + 1] = sayilar2[j];
			j--;
			sayilar2[j + 1] = gecici;
		}
	}

	for (int i = 0;i < 500;i++) {
		printf("Insertion Sort ile siralanmis dizi elemanlari = %d \n", sayilar2[i]);
	}
	bitis = clock();
	gecen_sure = ((double)(bitis - baslangic));
	printf("Insertion sort islemi %.2f saniye surdu.\n", gecen_sure);

	return 0;
}