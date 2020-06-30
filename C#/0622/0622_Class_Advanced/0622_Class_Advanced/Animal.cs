using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Class_Advanced
{
    class Animal
    {
        private string name;

        public Animal(string name = "NULL")
        {
            this.name = name;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }


        public virtual string info()
        {
            MessageBox.Show(this.name + " is Animal");
            return this.name + " is Animal";
        }

        public string Eat(string s)
        {
            return "Eating " + s;
        }
    }
}
