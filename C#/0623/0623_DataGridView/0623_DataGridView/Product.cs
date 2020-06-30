using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0623_DataGridView
{
    class Product
    {
        private string name;
        private int price;

        public Product(string name, int price)
        {
            this.name = name;
            this.price = price;

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
        public int PRICE
        {
            get
            {
                return price;
            }
            set
            {
                price = value;
            }
        }
    }
}
