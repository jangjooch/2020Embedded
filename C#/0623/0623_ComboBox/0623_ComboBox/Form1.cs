using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_ComboBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {            
            comboBox1.Items.Clear();            
            comboBox1.Items.Add("AddByCode01");
            comboBox1.Items.Add("AddByCode02");
            comboBox1.SelectedIndex = 0;

            listBox1.Items.Clear();            
            listBox1.Items.Add("Selection01");
            listBox1.Items.Add("Selection02");
            listBox1.Items.Add("Selection03");
            listBox1.SelectedIndex = 0;

            
            productBindingSource.Add(new Product("Potato", 200));
            productBindingSource.Add(new Product("Apple", 1200));
            productBindingSource.Add(new Product("Korean Melon", 700));
            comboBox2.SelectedIndex = 0;
        }

        private void ComboxBoxRecive(object sender, EventArgs e)
        {
            MessageBox.Show(comboBox1.SelectedItem.ToString());
        }

        private void ListBoxReceive(object sender, EventArgs e)
        {
            MessageBox.Show(listBox1.SelectedItem.ToString());
        }

        private void productBindingSource_Add(object sender, EventArgs e)
        {
            productBindingSource.Add(new Product("Cucomber", 300));
            productBindingSource.Add(new Product("Water Melon", 5000));
        }

        private void productShowInfo(object sender, EventArgs e)
        {
            MessageBox.Show(((Product)comboBox2.SelectedItem).NAME + " is selling at "
                + ((Product)comboBox2.SelectedItem).PRICE.ToString());
        }
    }
}
