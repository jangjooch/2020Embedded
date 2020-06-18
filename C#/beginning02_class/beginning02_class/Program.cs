using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace beginning02_class
{
    class Program
    {
        static void Main(string[] args)
        {
            Human human01 = new Human("Jang", 26, "123-456");
            human01.Personal();

            Human human02 = new Human("Lee");
            human02.Personal();

            Human human03 = new Human();
            human03.Personal();

            Console.WriteLine("------------");

            List<Human> men = new List<Human>()
            {
                new Human(), new Human()
            };
            foreach(Human i in men)
            {
                i.Personal();
            }

            Console.WriteLine("------------");

            men.Add(human01);
            men.Add(human02);
            men.Add(human03);
            foreach (Human i in men)
            {
                i.Personal();
            }            
            int idx_men = men.IndexOf(human01);
            Console.WriteLine(idx_men);
            idx_men = men.IndexOf(new Human("Lee")); // 이러한 방식으로는 못찾네
            Console.WriteLine(idx_men);
            foreach (Human i in men)
            {
                i.Personal();
            }

            Console.WriteLine("------------");

            Random rand = new Random();
            int r_int = rand.Next(1, 10);
            double r_double = rand.NextDouble();

            Console.WriteLine((int)(r_double * 10));

            Console.WriteLine("------------");

            Vehicle vehicle01 = new Vehicle();
            Airplane airplane01 = new Airplane();
            Cycle cycle01 = new Cycle(3);
            vehicle01.Activate();
            Console.WriteLine("#");
            airplane01.Activate();
            Console.WriteLine("#");
            cycle01.Activate();
            Console.WriteLine("------------");


            
        }
    }
}
