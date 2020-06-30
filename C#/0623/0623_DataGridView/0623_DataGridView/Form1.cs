using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_DataGridView
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 2;
            dataGridView1.Columns[0].Name = "Name";
            dataGridView1.Columns[1].Name = "Price";
            dataGridView1.Columns[0].HeaderText = "NAME";
            dataGridView1.Columns[1].HeaderText = "Price";

            string[] row1 = {"Potato", "700"};
            dataGridView1.Rows.Add(row1);
            string[] row2 = { "Melon", "5000" };
            dataGridView1.Rows.Add(row2);
            string[] row3 = { "Apple", "1500" };
            dataGridView1.Rows.Add(row3);
        }

        private void DataGridView_ItemReadAll(object sender, EventArgs e)
        {
            for(int i = 0; i < dataGridView1.Rows.Count - 1; i++)
            {
                string name = dataGridView1.Rows[i].Cells[0].Value.ToString();
                string price = dataGridView1.Rows[i].Cells[1].Value.ToString();
                MessageBox.Show("Data " + name + " is selling at " + price);
            }
        }

        private void DataGridView_ItemDataChange(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.Rows.Count - 1; i++)
            {
                string name = dataGridView1.Rows[i].Cells["Name"].Value.ToString();
                if (name.Equals("Potato"))
                {
                    dataGridView1.Rows[i].Cells[1].Value = 500;
                }
            }
        }
    }
}
