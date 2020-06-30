using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0622_HW_MemberSystem
{
    class User
    {
        private string name;
        private string phone;
        private int age;

        public User(string name = "NULL", string phone = "NULL", int age = 0)
        {
            this.name = name;
            this.phone = phone;
            this.age = age;
        }

        public string UserInfo()
        {
            return this.name + "|" + this.phone + "|" + this.age;
        }

        public string NAME
        {
            set
            {
                name = value;
            }
            get
            {
                return name;
            }
        }
        public string PHONE
        {
            set
            {
                phone = value;
            }
            get
            {
                return phone;
            }
        }
        public int AGE
        {
            set
            {
                age = value;
            }
            get
            {
                return age;
            }
        }
    }
}
