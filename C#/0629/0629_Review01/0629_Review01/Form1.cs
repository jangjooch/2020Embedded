using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0629_Review01
{
    public partial class Form1 : Form
    {
        List<Product> productsList;
        Dictionary<int,Product> productsDic;
        int contents;
        public Form1()
        {
            InitializeComponent();
            productsList = new List<Product>();
            productsDic = new Dictionary<int, Product>();
            contents = 0;
        }

        public void ListAdd(object sender, EventArgs e)
        {
            Random random = new Random();
            productsList.Add(new Product("Product" + contents.ToString(), (int)((random.NextDouble() * 1000)) + 1000));
            contents++;
        }
        public void ListShow(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            for(int i = 0; i < productsList.Count; i++)
            {
                richTextBox1.Text += productsList[i].productInfo() + "\r\n";
            }
            
        }
        public void ListRemove(object sender, EventArgs e)
        {
            int getNum = 0;
            bool status = false;
            if (textBoxListRemoveContent.Text == "")
            {
                MessageBox.Show("Input Index");
            }
            else
            {
                try
                {
                    getNum = int.Parse(textBoxListRemoveContent.Text);
                    status = true;
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Invaild Index Value");
                    textBoxListRemoveContent.Text = "";
                }
            }
            if (status)
            {
                if (getNum > productsList.Count - 1)
                {
                    MessageBox.Show("Index Out of Range");
                    textBoxListRemoveContent.Text = "";
                }
                else
                {
                    productsList.RemoveAt(getNum);
                    textBoxListRemoveContent.Text = "";
                    MessageBox.Show("Remove Complete");
                }
            }
        }


        public void DicAdd(object sender, EventArgs e)
        {
            Random random = new Random();
            Product pro = new Product( "Product" + contents, (int)(random.NextDouble() * 1000));
            productsDic.Add(pro.PRODUCTNUMBER, pro);
            contents++;
        }
        public void DicShow(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            foreach(int productNum in productsDic.Keys)
            {
                richTextBox1.Text +=  productsDic[productNum].productInfo() + "\r\n";
            }
        }
        public void DicRemove(object sender, EventArgs e)
        {
            int getNum = 0;
            bool status = false;
            if (textBoxDicRemoveContent.Text == "")
            {
                MessageBox.Show("Input Key");
            }
            else
            {
                try
                {
                    getNum = int.Parse(textBoxDicRemoveContent.Text);
                    status = true;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Invaild Key Value");
                    textBoxDicRemoveContent.Text = "";
                }
            }
            if (status)
            {
                if (productsDic.ContainsKey(getNum))
                {
                    productsDic.Remove(getNum);
                    textBoxDicRemoveContent.Text = "";
                    MessageBox.Show("Remove Complete");
                }
                else
                {
                    MessageBox.Show("No Such Key Value in Dictionary");
                    textBoxDicRemoveContent.Text = "";
                }
            }
        }
    }
}
