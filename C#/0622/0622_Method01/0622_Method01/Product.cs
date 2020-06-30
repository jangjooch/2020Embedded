using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Method01
{
    class Product
    {
        public const int cosntNumber = 123;
        // 상수. 변경불가
        public readonly int readonlyNumber = 123;
        // 생성자내부에서만 변경가능

        private static int count = 0;

        private string name;
        private int price;        

        public Product(string name = "NULL", int price = 0)
        {
            this.price = price;
            this.name = name;
            count++;
        }

        ~Product()
        {
            count--;
            MessageBox.Show("소멸자 " + count.ToString());
        }

        public string GetInfo()
        {
            return name + " " + price.ToString();
        }        
        public static int GetCount()
        {
            return count;
        }
    }
}
