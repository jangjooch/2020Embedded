using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace beginning02_class
{
    class Vehicle
    {
        public int wheel;

        public void Activate()
        {
            Console.WriteLine("This is Vehicle with " + wheel + " and Drive");
        }
        public Vehicle(int n = 0)
        {
            Console.WriteLine("Vehicle Created");
            wheel = n;
        }
    }

    class Airplane:Vehicle
    {
        
        public Airplane(int n = 6)
        {
            this.wheel = n;
            Console.WriteLine("Airplane Created");
        }

        ~Airplane()
        {

        }

        public void Activate()
        {
            Console.WriteLine("Airplane has " + this.wheel + " and Fly up the sky");
        }
    }

    class Cycle : Vehicle
    {
        public Cycle(int n)
        {
            this.wheel = n;
            Console.WriteLine("Cycle Created");
        }
    }
}
