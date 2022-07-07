using System;

namespace MergeSort
{

    class Program
    {

        static void Merge(int[] liczby, int lewo, int srodek, int prawo)
        {

            int i = lewo, j = srodek + 1, miejsce = lewo;
            int[] pomocnicza = (int[])liczby.Clone();

            while(i <= srodek && j <= prawo)
            {

                if (pomocnicza[i] <= pomocnicza[j]) { liczby[miejsce] = pomocnicza[i]; i++; }
                else { liczby[miejsce] = pomocnicza[j]; j++; }

                miejsce++;

            }

            while(i <= srodek) { liczby[miejsce] = pomocnicza[i]; i++; miejsce++; }
            while(j <= prawo) { liczby[miejsce] = pomocnicza[j]; j++; miejsce++; }

        }

        static void Merge_sort(int[] liczby, int lewo, int prawo)
        {

            int srodek = (prawo + lewo) / 2;

            if (lewo < prawo)
            {

                Merge_sort(liczby, lewo, srodek);
                Merge_sort(liczby, srodek + 1, prawo);

                Merge(liczby, lewo, srodek, prawo);

            }

        }

        static void Main()
        {

            int[] liczby = Array.ConvertAll(Console.ReadLine().Split(' '), liczba => int.Parse(liczba));

            Merge_sort(liczby, 0, liczby.Length - 1);

            foreach (var liczba in liczby) Console.Write(liczba + " ");

            Console.ReadKey();

        }

    }

}

