#include <stdio.h>
#include <stdlib.h>

int main ()
{

  int a, b;

  scanf("%i %i", &a, &b);
  
  a = b ^ a ^ (b = a);

  printf("%i %i", a, b);

  system("pause > nul");

  return 0;

}

/*

a = b ^ a ^ (b = a)

2 przypisania, 2 operacje XOR. Razem 4.

^ oznacza XOR.

XOR to alternatywa rozlaczna:
alternatywa (OR) to operacja zwracajaca 1, gdy co najmniej jedna z dwoch liczb jest rowna 1.
rozlaczna (X) oznacza, ze operacja ma zwrocic 0 gdy oby dwie liczby sa rowne 1.

Z powyzszego wynika tabela prawdy:

0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

*/
