#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* Do pierwiastkow i poteg */

float dajDelte(float a, float b, float c){
	
	return pow(b, 2) - ((float)4 * a * c); /* b^2 - 4ac */
	
}

float dajXkwadratowe(float a, float b, float delta, int plusminus){
	
	if(plusminus == 1) return ( (((-1) * b) + sqrt(delta)) / (2 * a) ); /* X1 (-b+sqrt(delta))/2a */
	else return ( (((-1) * b) - sqrt(delta)) / (2 * a) ); /* X2 (-b-sqrt(delta))/2a */
	
}

float dajXliniowe(float b, float c){
	
	float wynik = ( ((-1) * c) / b);
	if(wynik == ((-1) * 0)) return (float)0; /* -0 wystepuje w C, wystarczy zwrocic na sztywno 0 */
	else return wynik;
	
}

void wyswietlWyniki(float x1, float x2){
	
	float temp = x1;
	
	if(x1 > x2){
		
		x1 = x2;
		x2 = temp;
		
	}
	
	printf("2 %g %g", x1, x2);
	
	return;
	
}

int main(int argc, char *argv[]) {
	
	float a, b, c;
	
	if(scanf("%f %f %f", &a, &b, &c) != 3) return -1;

	if(a == 0){ /* To nie jest funkcja kwadratowa */
		
		if(b == 0){ /* ... ani nawet liniowa */
		
			if(c == 0) { /* Funkcja stala 0x^2 + 0x + 0 = 0, x c R */
				
				printf("R");
				
			}
			else { /* Funkcja stala, ale x c R \ { 0 } dla x = y = 0, wiec sprzecznosc */
				
				printf("0");
				
			}
			
		}
		else { /* Funkcja liniowa bx + c = 0 <=> bx = -c -> x = -c/b, funkcja liniowa z zalozenia ma 1 rozwiazanie */
			
			printf("1 %g", dajXliniowe(b, c));
			
		}
		
	}
	else { /* Funkcja kwadratowa ax^2 + bx + c = 0*/
		
		float delta = dajDelte(a, b, c);
		
		if(delta < 0) printf("0"); /* Delta < 0 -> brak rozwiazan rzeczywistych */
		else if(delta == 0) printf("1 %g", dajXkwadratowe(a, b, delta, 1)); /* delta = 0 -> jeden wynik, nie wazne czy X1 czy X2 pierwiastek z 0 to 0, zatem wynik bedzie ten sam */
		else wyswietlWyniki(dajXkwadratowe(a, b, delta, 1), dajXkwadratowe(a, b, delta, 2)); /* delta > 0 -> 2 wyniki */
		
	}
	
	system("pause > nul");
	
	return 0;
	
}

