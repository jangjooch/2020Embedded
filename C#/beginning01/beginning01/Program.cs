using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace beginning01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("int : " + sizeof(int));
            Console.WriteLine("byte : " + sizeof(byte));
            Console.WriteLine("BYTE : " + sizeof(Byte));

            Console.Write("Input string : ");
            string str01 = Console.ReadLine();
            Console.WriteLine("ReadLine str : " + str01);

            try
            {
                int numget = int.Parse(str01);
                Console.WriteLine(str01 + " -> " + numget);
            }
            catch(Exception ex)
            {
                Console.WriteLine("Exception");
                Console.WriteLine(ex.ToString());
                
            }
            finally
            {
                Console.WriteLine("Parse int done");
            }

            double piCopy = Math.PI;
            Console.WriteLine(piCopy);
            Console.WriteLine(piCopy.ToString("0.00")); // 실수형 패턴 Set
        }
    }
}
