using System;
using System.Linq;

namespace CountSort
{

    class Program
    {

        static int[] CountSort(int[] liczby)
        {

            var wystapienia = new uint[liczby.Min() < 0 ? (liczby.Max() - liczby.Min() + 1) : (liczby.Max() + 1)];
            var wynik = new int[liczby.Length];

            foreach (var liczba_indeks in liczby) wystapienia[liczby.Min() < 0 ? (liczba_indeks - liczby.Min()) : liczba_indeks]++;

            uint miejsce = 0;
            int liczba = liczby.Min();
            foreach (var wystapienie in wystapienia)
            {

                for (uint j = 1; j <= wystapienie; j++)
                {

                    wynik[miejsce] = liczba;
                    miejsce++;

                }

                liczba++;

            }

            return wynik;

        }

        static void Main()
        {

            foreach (var liczba in CountSort(Array.ConvertAll(Console.ReadLine().Split(' '), liczba => int.Parse(liczba)))) Console.Write(liczba + " ");

            Console.ReadKey();

        }

    }

}

