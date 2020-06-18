using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0618_HW01
{
    class User
    {
        public string name;
        public string phone;

        public User(string n = "NULL", string p = "NULL")
        {
            name = n;
            phone = p;
        }

        public void Personal()
        {
            Console.WriteLine("NAME : " + name + "\tPHONE : " + phone);
        }

    }
}
