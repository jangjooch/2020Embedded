using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0623_HW01.Model
{
    class User
    {
        private string name;
        private string phone;
        private int age;

        public User(string name = "NULL" , string phone = "***-***", int age = 0)
        {
            this.name = name;
            this.phone = phone;
            this.age = age;
        }

        public string Personal()
        {
            return name + "|" + phone + "|" + age.ToString();
        }

        public string NAME
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public string PHONE
        {
            get
            {
                return phone;
            }
            set
            {
                phone = value;
            }
        }
        public int AGE
        {
            get
            {
                return age;
            }
            set
            {
                age = value;
            }
        }
    }
}
