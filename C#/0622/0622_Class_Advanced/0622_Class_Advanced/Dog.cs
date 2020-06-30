using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Class_Advanced
{
    class Dog:Animal
    {
        int age;
        public Dog(string name = "NULL", int a = 0)
        {
            this.Name = name;
            this.age = a;
        }

        public override string info()
        {
            return this.Name + " is Dog";
        }

        public string Bark()
        {
            MessageBox.Show("Dog " + this.Name + " is Barking and Its " + this.age + " years old");
            return "Dog " + this.Name + " is Barking";
        }
    }

    class Cat : Animal
    {
        public Cat(string name = "NULL")
        {
            this.Name = name;
        }

        public override string info()
        {
            return this.Name + " is Cat";
        }

        public string Mewo()
        {
            MessageBox.Show("Cat " + this.Name + " is Mewoing");
            return "Cat " + this.Name + " is Mewoing";
        }
    }
}
