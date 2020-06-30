using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0619_DicVer
{
    class User
    {
        private string name;
        private readonly string phone;
        private int age;

        public string getName()
        {
            return name;
        }
        public string getPhone()
        {
            return phone;
        }
        public int getAge()
        {
            return age;
        }
        public void setAge(int age)
        {
            this.age = age;
        }
        public void setName(string name)
        {
            this.name = name;
        }
        

        public User(string n = "NULL", string p = "NULL", int a = 0)
        {
            name = n;
            phone = p;
            age = a;
        }

        public string Personal()
        {
            string personal = "";
            personal += name;
            personal += "|";
            personal += phone;
            personal += "|";
            personal += age;
            return personal;
        }
    }
}
