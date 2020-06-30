using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0622_Method01
{
    class Box
    {
        private static int count = 0;

        private readonly string companyName;
                
        private int height;
        // height의 getter setter
        public int Height
        {
            get
            {
                return height;
            }
            set
            {
                if(value < 0)
                {
                    height = 1;
                }
                else
                {
                    height = value;
                }
            }
        }

        private int width;
        // width의 getter setter
        public int Width
        {
            get
            {
                return width;
            }
            set
            {
                if(value < 0)
                {
                    width = 1;
                }
                else
                {
                    width = value;
                }
            }
        }
        
        public Box(int height = 0, int width = 0, string companyName = "Unknown")
        {
            this.height = height;
            this.width = width;
            this.companyName = companyName;
            count++;
        }
        
        public string BoxInfo()
        {
            return height + " * " + width + " Box made by " + companyName + "| Total : " + count + "";
        }

    }
}
