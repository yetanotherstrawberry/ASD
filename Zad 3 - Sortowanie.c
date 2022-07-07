#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* Do randoma */
#include <math.h> /* Do pow()'a */
#include <string.h> /* Do memcpy() */

int *tab; /* Tutaj trzymamy liczby */
int *kopia; /* Tutaj bezpiecznie trzymamy kopie tablicy, ktora przywrocimy po skonczeniu pracy algorytmu sortowania - algorytm opecuje na *tab */

void genTab(int ile, int jaka){
	
	int i = 0,  *wskazniczek = malloc(sizeof(int) * ile);
	
	if(jaka == 1){ /* Niemalejaco */
		
		for(; i < ile; i++){
			
			*(wskazniczek + i) = i + 1;
			
		}
		
	}
	else if(jaka == 2){ /* Losowa */
		
		for(; i < ile; i++){
			
			*(wskazniczek + i) = rand() % 100 + 1;
			
		}
		
	}
	else { /* Nierosnaco */
		
		for(; i < ile; i++){
			
			*(wskazniczek + i) = ile - i;
			
		}
		
	}
	
	tab = wskazniczek;
	
	kopia = malloc(sizeof(int) * ile);
	memcpy(kopia, tab, sizeof(int) * ile);
	
	return;
	
}

void wyswietlTab(int ile){
	
	int i = 0;
	
	for(; i < ile; i++){
		
		printf("%i ", *(tab + i));
		
	}
	
	printf("\n");
	
	return;
	
}

double mroczneBabelki(int ile, int typ){
	
	clock_t start = clock();
	int i, j, temp;
	
	if((ile >= pow(10, 5) && typ == 2) || (ile >= pow(10, 5) && typ == 3) || ile >= pow(10, 6)) return 60;
	
	for(i = 0; i < ile; i++, j = 0)
		for(; j < ile - 1; j++)
			if(*(tab + j) > *(tab + j + 1)){
				
				temp = *(tab + j + 1);
				*(tab + j + 1) = *(tab + j);
				*(tab + j) = temp;
				
			}
	
	return (clock() - start)/(double)CLOCKS_PER_SEC;
	
}

double aGdybyToPoliczyc(int ile, int typ){
	
	clock_t start = clock();
	int temp = 0, j, i = 1, max = *tab, *liczydlo = NULL; /* i = 1, bo 0 element tablicy juz jest przypisany do max */
	
	for(; i < ile; i++) if(*(tab + i) > max) max = *(tab + i); /* Potrzebuje maksymalnej liczby, zeby stworzyc tablice ilosci wystapien kazdej liczby. */
	liczydlo = calloc(max + 1, sizeof(int)); /* calloc() wypelnia miejsce w pamieci zerami; +1, bo zerowe miejsce istnieje w tablicy */
	for(i = 0; i < ile; i++) (*(liczydlo + *(tab + i)))++; /* Tutaj liczymy */
	for(i = 0; i <= max; i++, j = 0) /* Tutaj wyjatkowo <0, max>, bo maksymalna liczba tez musi zostac policzona i ma miejsce w tablicy */
		for(; j < *(liczydlo + i); j++){
			
			*(tab + temp) = i;
			temp++;
			
		}
	
	free(liczydlo);
	
	return (clock() - start)/(double)CLOCKS_PER_SEC;
	
}

double czasNaWybor(int ile, int typ){
	
	clock_t start = clock();
	int i, miejsce = 0, temp_min, temp_miejsce;
	
	if(ile >= pow(10, 6)) return 60;
	
	do {
		
		temp_min = *(tab + miejsce);
		temp_miejsce = miejsce;
		
		for(i = miejsce + 1; i < ile; i++){
			
			if(*(tab + i) < temp_min){
			
				temp_min = *(tab + i);
				temp_miejsce = i;
			
			}
			
		}
		
		*(tab + temp_miejsce) = *(tab + miejsce);
		*(tab + miejsce) = temp_min;

		miejsce++;
		
	} while(miejsce != (ile - 1));
	
	return (clock() - start)/(double)CLOCKS_PER_SEC;
	
}

int main(int argc, char *argv[]) {
	
	int i, j;
	double czas;
	
	srand((unsigned)time(NULL));
	
	for(i = 1; i <= 7; i++){
		
		printf("rozmiar: 10^%i", i);
		
		for(j = 1; j <= 3; j++){
		
			genTab(pow(10, i), j);
			if(j == 1) printf("\nniemalejaco:\n");
			else if(j == 2) printf("losowo:\n");
			else printf("nierosnaco:\n");
			if(i == 1) wyswietlTab(pow(10, i));
			
			czas = mroczneBabelki(pow(10, i), j);
			if(czas == 60) printf("BUBBLE-SORT: 60+\n");
			else printf("BUBBLE-SORT: %g\n", czas);
			if(i == 1) wyswietlTab(pow(10, i));
			
			memcpy(tab, kopia, sizeof(int) * pow(10, i)); /* Przywracamy tablice do stanu sprzed losowania */
			czas = aGdybyToPoliczyc(pow(10, i), j);
			if(czas == 60) printf("COUNT-SORT: 60+\n");
			else printf("COUNT-SORT: %g\n", czas);
			if(i == 1) wyswietlTab(pow(10, i));
			
			memcpy(tab, kopia, sizeof(int) * pow(10, i));
			czas = czasNaWybor(pow(10, i), j);
			if(czas == 60) printf("SELECT-SORT: 60+\n");
			else printf("SELECT-SORT: %g\n", czas);
			if(i == 1) wyswietlTab(pow(10, i));
			
			free(tab);
			free(kopia);
		
		}
		
	}
	
	return 0;
	
}
