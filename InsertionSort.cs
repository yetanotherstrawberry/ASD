using System;

namespace InsertionSort
{

    class Program
    {

        static void InsertionSort(int[] liczby)
        {

            for (int i = 1; i < liczby.Length; i++)
            {

                int key = liczby[i], j = i - 1;

                while (j >= 0 && liczby[j] > key) liczby[j + 1] = liczby[j--];

                liczby[j + 1] = key;

            }

        }

        static void Main()
        {

            int[] liczby = Array.ConvertAll(Console.ReadLine().Split(' '), liczba => int.Parse(liczba));

            InsertionSort(liczby);

            foreach (var liczba in liczby) Console.Write(liczba + " ");

            Console.ReadKey();

        }

    }

}

