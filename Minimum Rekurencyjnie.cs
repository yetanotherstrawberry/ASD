using System;

namespace Min
{

    class Program
    {

        static int Min(int[] tab, int lewo, int prawo)
        {

            if(prawo - lewo > 2)
            {

                int sr = (lewo + prawo) / 2;
                int a = Min(tab, lewo, sr);
                int b = Min(tab, sr + 1, prawo);

                if (a < b) return a;
                else return b;

            }
            else
            {

                if (tab[lewo] < tab[prawo]) return tab[lewo];
                else return tab[prawo];

            }

        }

        static void Main(string[] args)
        {

            int[] liczby = Array.ConvertAll(Console.ReadLine().Split(' '), liczba => int.Parse(liczba));
            Console.WriteLine(Min(liczby, 0, liczby.Length - 1));

            Console.ReadKey();

        }

    }

}

