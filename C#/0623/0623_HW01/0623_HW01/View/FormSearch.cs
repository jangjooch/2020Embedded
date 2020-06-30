using _0623_HW01.Control;
using _0623_HW01.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_HW01.View
{
    public partial class FormSearch : Form
    {
        public FormSearch()
        {            
            InitializeComponent();
            radioButtonName.Checked = true;
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();

            int select = 0;

            if (radioButtonName.Checked)
            {
                select = 1;
            }
            else if (radioButtonPhone.Checked)
            {
                select = 2;
            }
            else if (radioButtonAge.Checked)
            {
                select = 3;
            }
            UsersEditing usersEditing = new UsersEditing();
            List<User> foundKey = usersEditing.SearchUser(textBoxContent.Text, select);

            dataGridView1.ColumnCount = 3;
            dataGridView1.Columns[0].Name = "Name";
            dataGridView1.Columns[1].Name = "Phone";
            dataGridView1.Columns[2].Name = "Age";
            dataGridView1.Columns[0].HeaderText = "NAME";
            dataGridView1.Columns[1].HeaderText = "PHONE";
            dataGridView1.Columns[2].HeaderText = "AGE";

            foreach(User getUser in foundKey)
            {
                string[] data = { getUser.NAME, getUser.PHONE, getUser.AGE.ToString() };
                dataGridView1.Rows.Add(data);
            }
        }
    }
}
