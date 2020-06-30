using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0629_Review01
{
    class Product
    {
        public Product(string name = "NULL", int productNumber = 0)
        {
            this.productNumber = productNumber;
            this.name = name;
        }

        private string name;
        private int productNumber;
        
        public string productInfo()
        {
            return name + "'s Serial Number is " + productNumber.ToString();
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

        public int PRODUCTNUMBER
        {
            set
            {
                productNumber = value;
            }
            get
            {
                return productNumber;
            }
        }
    }
}
