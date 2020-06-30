using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Method01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonProductCreate_Click(object sender, EventArgs e)
        {
            int count;
            Product product01 = new Product("TEST", 500);
            count = Product.GetCount();
            MessageBox.Show(product01.GetInfo() + " | " + count.ToString());

            Product product02 = new Product();
            count = Product.GetCount();
            MessageBox.Show(product02.GetInfo() + " | " + count.ToString());
        }

        private void CreateProduct()
        {
            Product pro = new Product();
            MessageBox.Show(Product.GetCount().ToString());            
        }

        private void buttonCre_Click(object sender, EventArgs e)
        {
            CreateProduct();
        }

        private void buttonDis_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Product.GetCount().ToString());
        }

        private void buttonBoxCre_Click(object sender, EventArgs e)
        {
            Box box = new Box(10, 2, "ABC");
            //box.width = 20;
            //box.height = 50;
            box.Height = 100;
            box.Width = -10;
            MessageBox.Show(box.BoxInfo());

            Box box2 = new Box(10, -10, "QWE");
            MessageBox.Show(box2.BoxInfo());            
        }
    }
}
