using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Class_Advanced
{
    public partial class Form1 : Form
    {
        List<Animal> animals;

        public Form1()
        {
            InitializeComponent();
            animals = new List<Animal>();            
        }

        public void Create_Animal(object sender, EventArgs e)
        {
            Animal animal = new Animal("Unknown");
            animal.info();
            animals.Add(animal);
        }

        public void Create_Dog(object sender, EventArgs e)
        {
            Animal dog = new Dog("Bowi",12);
            ((Dog)dog).Bark();
            animals.Add(dog);

            Dog testdog = new Dog("Wow",12);
            animals.Add(testdog);
        }

        public void Create_Cat(object sender, EventArgs e)
        {
            Animal cat = new Cat("ThreeColor");
            ((Cat)cat).Mewo();
            animals.Add(cat);
        }

        private void buttonListAnimals_Click(object sender, EventArgs e)
        {
            foreach(object o in animals)
            {
                if(o is Dog)
                {
                    ((Dog)o).Bark();
                }
                else if(o is Cat)
                {
                    ((Cat)o).Mewo();
                }
                else if(o is Animal)
                {
                    ((Animal)o).info();
                }
            }
        }

        private void buttonTest_Click(object sender, EventArgs e)
        {
            Dog test = new Dog("Test", 10);
            Animal animal = test as Animal;

            Dog dog = animal as Dog;
            Cat cat = animal as Cat;

            if(dog != null)
            {
                dog.Bark();
            }
            if(cat != null)
            {
                cat.Mewo();
                // 초기에 Dog로 생성되었던 것을 Animal로 캐스팅 후
                // Cat으로 Casting하면 생성되지 않는다.
                // Dog와 Cat은 상속관계가 아니기에 생성될 수 없다.
            }
        }
    }
}
