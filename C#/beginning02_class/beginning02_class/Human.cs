using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace beginning02_class
{
    class Human
    {
        // 인스턴스
        private string name { get; set; }
        private int age { get; set; }
        private string pNumber { get; set; }
        

        // 메소드
        public void Personal()
        {
            Console.WriteLine("NAME : " + name + "\nAGE : " + age + "\nPersonl Number : " + pNumber);
        }
        
        public void setName(string n)
        {
            name = n;
        }

        public void setAge(int a)
        {
            age = a;
        }

        public void setPNumber(string p)
        {
            pNumber = p;
        }

        public string getName()
        {
            return name;
        }
        public int getAge()
        {
            return age;
        }
        public string getPNumber()
        {
            return pNumber;
        }
        // 생성자
        public Human(string n = "NULL", int a = 1, string p = "000-000")
        {
            name = n;
            age = a;
            pNumber = p;
        }
        ~Human()
        {
            Console.WriteLine("Delete Information");
        }
    }
}
