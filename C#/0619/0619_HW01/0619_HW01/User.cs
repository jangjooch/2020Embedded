using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0619_HW01
{
    class User
    {
        private string name;
        private string phone;
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
        public void setPhone(string phone)
        {
            this.phone = phone;
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
